/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 08:15:35 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/24 10:05:20 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/matvec.h"

double	vec_len(t_vec v)
{
	return (sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]));
}

double	dot(t_vec a, t_vec b)
{
	return ((a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]));
}

void	normalise(t_vec v)
{
	double l;

	l = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
	if (l > 0)
	{
		l = 1 / sqrt(l);
		v[0] *= l;
		v[1] *= l;
		v[2] *= l;
	}
}

double	mind(double a, double b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

double	maxd(double a, double b)
{
	if (a < b)
		return (b);
	else
		return (a);
}