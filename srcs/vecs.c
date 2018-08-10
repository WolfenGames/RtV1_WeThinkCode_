/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:38:41 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/10 09:25:17 by jwolf            ###   ########.fr       */
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

t_vec	mult_vec_vec(t_vec a, t_vec b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return (a);
}

t_vec	add_vec_vec(t_vec a, t_vec b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
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

t_vec	minus_vec_vec(t_vec a, t_vec b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_vec	vec_swap(t_vec a, t_vec b)
{
	t_vec	temp;

	temp.x = a.x;
	a.x = b.x;
	b.x = temp.x;
	temp.y = a.z;
	a.y = b.y;
	b.y = temp.y;
	temp.z = a.z;
	a.z = b.z;
	b.z = temp.z;
	return (temp);
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