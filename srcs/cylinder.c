/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 11:23:31 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/23 08:38:24 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"
/*
double		*c_getnorm(t_vec point, t_vec norm, t_obj *obj)
{
	t_vec		opoint;
	t_matrix	rot;
	t_vec		tempvec;
	double		a;

	transform(obj->wto, point, opoint);
	FILLVEC(norm, 0, 1, 0);
	FILLVEC(tempvec, opoint[0], opoint[1], 0);
	fill_m_rot_z(rot, find_angle(norm, tempvec) * (tempvec[0] < 0 ? -1 : 1));
	a = find_angle(norm, tempvec);
	obj->tex[0] = 1 - ((opoint[0] < 0) ? (2 * PI - a) : a) / (2 * PI);
	obj->tex[1] = ((obj->height / 2) - opoint[2]) / obj->height;
	if (length(tempvec) < obj->r)
		v_multi(norm, -1, norm);
	transformvec(rot, norm, norm);
	transformvec(obj->otw, norm, norm);
	return (norm);
}
*/
static int	get_abc(double near, double t[3], t_ray *ray, t_obj *obj)
{
	t_ray	tempray;
	double	var[3];

	transformvec(obj->wto, ray->dir, tempray.dir);
	transform(obj->wto, ray->org, tempray.org);
	var[0] = tempray.dir[0] * tempray.dir[0] + tempray.dir[1] * tempray.dir[1];
	var[1] = 2 * (tempray.org[0] * tempray.dir[0]
		+ tempray.org[1] * tempray.dir[1]);
	var[2] = tempray.org[0] * tempray.org[0]
		+ tempray.org[1] * tempray.org[1] - obj->radius2;
	if (!quad(var[0], var[1], var[2], t))
		return (0);
	t[2] = t[0] < 0 ? t[1] : t[0];
	if (t[2] < 0 || t[2] > near)
		return (0);
	return (1);
}

static int	c_bound(t_vec temp, t_obj *obj, double t[3], t_ray tempray)
{
	double c;

	if (temp[2] < -obj->size[0] / 2 + obj->org[2]
		|| temp[2] > obj->size[0] / 2 + obj->org[2])
	{
		if (t[2] == t[1])
			return (0);
		t[2] = t[1];
		v_multi(tempray.dir, t[2], temp);
		v_add(tempray.org, temp, temp);
		c = atan2f(temp[1], temp[0]);
		if (c < 0.0f)
			c += 2.0f * M_PI;
		if (temp[2] < -obj->size[0] / 2 + obj->org[2]
			|| temp[2] > obj->size[0] / 2 + obj->org[2])
			return (0);
	}
	return (1);
}

int			inter_cylinder(t_ray *ray, t_obj *obj, double *near)
{
	t_vec	temp;
	t_ray	tempray;
	double	c;
	double	t[3];

	if (!get_abc(*near, t, ray, obj))
		return (0);
	transformvec(obj->wto, ray->dir, tempray.dir);
	transform(obj->wto, ray->org, tempray.org);
	v_multi(tempray.dir, t[2], temp);
	v_add(tempray.org, temp, temp);
	c = atan2f(temp[1], temp[0]);
	if (c < 0.0f)
		c += 2.0f * M_PI;
	if (!c_bound(temp, obj, t, tempray))
		return (0);
	if (*near < t[2])
		return (0);
	*near = t[2];
	return (1);
}