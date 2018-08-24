/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphericals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 09:04:42 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/24 09:56:43 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void sphere_norm(t_ray *ray, t_obj *obj, double n)
{
	t_ray	r;

	ft_memmove(&r, ray, sizeof(t_ray));
	mult_vec_f(r.dir, n, r.dir);
	add_vec_vec(r.dir, r.org, obj->point);
	minus_vec_vec(obj->point, obj->org, obj->norm);
	normalise(obj->norm);
}

int		    inter_sphere(t_ray *ray, t_obj *obj, double *n)
{
	t_vec	l;
	t_vec	v;
	double	t[2];

	minus_vec_vec(ray->org, obj->org, l);
	v[0] = dot(ray->dir, ray->dir);
	v[1] = 2 * dot(l, ray->dir);
	v[2] = dot(l, l) - obj->radius2;
	if (!quad(v, t))
		return (0);
	if (t[0] < 0)
		t[0] = t[1];
	if (t[0] < 0)
		return (0);
	if (t[0] > *n)
		return (0);
	*n = t[0];
	sphere_norm(ray, obj, *n);
	return (1);
}