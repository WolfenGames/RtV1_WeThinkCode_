/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:56:44 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/07 14:30:26 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

double	dot(t_vec v)
{
	return (vec_len(v));
}

double	dot_f(t_vec v, double a)
{
	return (a * v.x + a * v.y + a * v.z);
}

t_bool	intersects(t_obj o, t_vec o_ray, t_ray r, float *t[2])
{
	t_vec	l;
	double	tca;
	double	d2;
	double	thc;

	l = minus_vec(o.mat[0], r.dir);
	tca = dot_f(l, r.dir);
	if (tca < 0)
		return (FALSE);
	d2 = dot(l) - tca * tca;
	if (d2 > o.radius2)
		return (FALSE);
	thc = sqrt(o.radius2 - d2);
	*t[0] = tca - thc;
	*t[1] = tca + thc;
}

float	mix(float a, float b, float mix)
{
	return (b * mix + a * (1 - mix));
}