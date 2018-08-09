/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:38:41 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/09 08:04:06 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_vec	normalise(t_vec v)
{
	double	nor2;
	double	inv_nor;

	nor2 = (v.x * v.x + v.y * v.y + v.z * v.z);
	if (nor2 > 0)
	{
		inv_nor = 1 / sqrt(nor2);
		v.x *= inv_nor;
		v.y *= inv_nor;
		v.z *= inv_nor;
	}
	return (v);
}

t_vec	mult_vec(t_vec v, double a)
{
	v.x *= a;
	v.y *= a;
	v.z *= a;
	return (v);
}

t_vec	add_vec(t_vec v, double a)
{
	v.x += a;
	v.y += a;
	v.z += a;
	return (v);
}

t_vec	minus_vec(t_vec v, double a)
{
	v.x -= a;
	v.y -= a;
	v.z -= a;
	return (v);
}

t_vec	vec_flip(t_vec v)
{
	v.x = -v.x;
	v.y = -v.y;
	v.z = -v.z;
	return (v);
}

double	vec_len(t_vec v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}