/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conicals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 10:33:57 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/24 13:13:08 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		*cone_getnorm(t_vec point, t_vec norm, t_obj *obj)
{
	t_matrix	norm_rot;
	t_vec		tempvec;
	t_matrix	temp;
	double		a;

	norm[0] = 0;
	norm[1] = 1;
	norm[2] = 0;
	tempvec[0] = point[0];
	tempvec[1] = point[1];
	tempvec[2] = 0;
	a = atan((obj->radius) / obj->size[0]);
	fill_mat_rot_x(norm_rot, a);
	fill_mat_rot_z(temp, angle_find(norm, tempvec) * (tempvec[0] < 0 ? -1 : 1));
	a = angle_find(norm, tempvec);
	mult_mat(norm_rot, temp, norm_rot);
	mult_vec(norm_rot, norm, norm);
	if (vec_len(tempvec) < (obj->radius * (1 - (point[2] / obj->size[0] + 0.5))))
		mult_vec_f(obj->norm, -1, obj->norm);
	return (norm);
}

static void plane_norm(t_ray *ray, t_obj *obj, double n)
{
	t_ray	r;

	ft_memmove(&r, ray, sizeof(t_ray));
	mult_vec_f(r.dir, n - 0.0000001, r.dir);
	add_vec_vec(r.dir, r.org, obj->point);
	cone_getnorm(obj->point, obj->norm, obj);
    mult_trans(obj->otw, obj->point, obj->point);
    mult_vec(obj->otw, obj->norm, obj->norm);
	normalise(obj->norm);
}

static int	get_abc(double near, double t[3], t_ray *ray, t_obj *obj)
{
	t_ray	tempray;
	double	var[3];
	double	c;

	mult_vec(obj->wto, ray->dir, tempray.dir);
	mult_trans(obj->wto, ray->org, tempray.org);
	c = pow((obj->radius / obj->size[0]) ,2);
	var[0] = tempray.dir[0] * tempray.dir[0] + tempray.dir[1] * tempray.dir[1]
		- c * tempray.dir[2] * tempray.dir[2];
	var[1] = 2 * (tempray.org[0] * tempray.dir[0] + tempray.org[1]
		* tempray.dir[1]
		- c * (tempray.org[2] - obj->size[0] / 2) * tempray.dir[2]);
	var[2] = tempray.org[0] * tempray.org[0] + tempray.org[1] * tempray.org[1]
		- c * (tempray.org[2] - obj->size[0] / 2)
		* (tempray.org[2] - obj->size[0] / 2);
	if (!quad(var, t))
		return (0);
	t[2] = t[0] < 0 ? t[1] : t[0];
	if (t[2] < 0 || t[2] > near)
		return (0);
	return (1);
}

static int	cone_bound(t_vec temp, t_obj *obj, double t[3], t_ray tempray)
{
	double c;

	if (temp[2] < -obj->size[0] / 2
		|| temp[2] > obj->size[0] / 2)
	{
		if (t[2] == t[1])
			return (0);
		t[2] = t[1];
		mult_vec_f(tempray.dir, t[2], temp);
		add_vec_vec(tempray.org, temp, temp);
		c = atan2f(temp[1], temp[0]);
		if (c < 0.0f)
			c += 2.0f * M_PI;
		if (temp[2] < -obj->size[0] / 2
			|| temp[2] > obj->size[0] / 2)
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
	mult_trans(obj->wto, ray->org, tempray.org);
	mult_vec_f(tempray.dir, t[2], temp);
	add_vec_vec(tempray.org, temp, temp);
	c = atan2f(temp[1], temp[0]);
	if (c < 0.0f)
		c += 2.0f * M_PI;
	if (!cone_bound(temp, obj, t, tempray))
		return (0);
	if (*near < t[2])
		return (0);
	*near = t[2];
	plane_norm(&tempray, obj, *near);
	return (1);
}