/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 11:34:21 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/21 06:53:17 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/* double		*cone_getnorm(t_vec point, t_vec norm, t_obj *obj)
{
	t_vec		opoint;
	t_matrix	norm_rot;
	t_vec		tempvec;
	t_matrix	temp;
	double		a;

	transform(obj->wto, point, opoint);
	FILLVEC(norm, 0, 1, 0);
	FILLVEC(tempvec, opoint[0], opoint[1], 0);
	a = atan((obj->height * obj->ratio) / obj->height);
	fill_m_rot_x(norm_rot, a);
	fill_m_rot_z(temp, find_angle(norm, tempvec) * (tempvec[0] < 0 ? -1 : 1));
	a = find_angle(norm, tempvec);
	obj->tex[0] = 1 - ((opoint[0] < 0) ? (2 * PI - a) : a) / (2 * PI);
	obj->tex[1] = ((obj->height / 2) - opoint[2]) / obj->height;
	m4_mult(norm_rot, temp, norm_rot);
	transformvec(norm_rot, norm, norm);
	transformvec(obj->otw, norm, norm);
	return (norm);
} */

static int	get_abc(double near, double t[3], t_ray *ray, t_obj *obj)
{
	t_ray	tempray;
	double	var[3];
	double	c;

	mult_vec(obj->wto, ray->dir, tempray.dir);
	mult_trans(obj->wto, ray->ori, tempray.ori);
	c = (obj->size[0]/obj->radius) * (obj->size[0]/obj->radius);
	var[0] = tempray.dir[0] * tempray.dir[0] + tempray.dir[1] * tempray.dir[1]
		- c * tempray.dir[2] * tempray.dir[2];
	var[1] = 2 * (tempray.ori[0] * tempray.dir[0] + tempray.ori[1]
		* tempray.dir[1]
		- c * (tempray.ori[2] - obj->size[0] / 2) * tempray.dir[2]);
	var[2] = tempray.ori[0] * tempray.ori[0] + tempray.ori[1] * tempray.ori[1]
		- c * (tempray.ori[2] - obj->size[0] / 2)
		* (tempray.ori[2] - obj->size[0] / 2);
	if (!quad(var[0], var[1], var[2], t))
		return (0);
	t[2] = t[0] < 0 ? t[1] : t[0];
	if (t[2] < 0 || t[2] > near)
		return (0);
	return (1);
}

static int	cone_bound(t_vec temp, t_obj *obj, double t[3], t_ray tempray)
{
	double c;

	if (temp[2] < -obj->size[0] / 2 + obj->ori[2]
		|| temp[2] > obj->size[0] / 2 + obj->ori[2])
	{
		if (t[2] == t[1])
			return (0);
		t[2] = t[1];
		mult_vec_f(tempray.dir, t[2], temp);
		add_vec_vec(tempray.ori, temp, temp);
		c = atan2f(temp[1], temp[0]);
		if (c < 0.f)
			c += 2.0f * M_PI;
		if (temp[2] < -obj->size[0] / 2 + obj->ori[2]
			|| temp[2] > obj->size[0] / 2 + obj->ori[2])
			return (0);
	}
	return (1);
}

int			inter_cone(t_ray *ray, t_obj *obj, double *near)
{
	t_vec	temp;
	t_ray	tempray;
	double	c;
	double	t[3];

	if (!get_abc(*near, t, ray, obj))
		return (0);
	mult_vec(obj->wto, ray->dir, tempray.dir);
	mult_trans(obj->wto, ray->ori, tempray.ori);
	mult_vec_f(tempray.dir, t[2], temp);
	add_vec_vec(tempray.ori, temp, temp);
	c = atan2f(temp[1], temp[0]);
	if (c < 0.0f)
		c += 2.0f * M_PI;
	if (!cone_bound(temp, obj, t, tempray))
		return (0);
	if (*near < t[2])
		return (0);
	*near = t[2];
	return (1);
}