/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 06:34:22 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/27 07:53:04 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		lightstuff(t_obj *o, t_raytrace *r)
{
	t_ray	ray;
	t_vec	tmp;
	double	n;

	vec_dup(o->point, ray.org);
	minus_vec_vec(LSO, ray.org, ray.dir);
	n = vec_len(ray.dir);
	normalise(ray.dir);
	add_vec_vec(ray.org, mult_vec_f(o->norm, 0.000000001, tmp), ray.org);
	if (obj_index(r, &ray, &n) != -1)
		return (scale_colour(o->surface_col, 0.07));
	return (maxd(scale_colour((colour_grad(scale_colour(o->surface_col,
		mind(dot(o->norm, ray.dir), 1.0)),
		o->surface_col, 0.07)), mind(LI / n, 1.0)),
		scale_colour(o->surface_col, 0.07)));
}
