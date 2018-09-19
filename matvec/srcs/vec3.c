/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 08:20:15 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/27 06:43:49 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/matvec.h"

double	*mult_vec_f(t_vec v, double a, t_vec r)
{
	r[0] = v[0] * a;
	r[1] = v[1] * a;
	r[2] = v[2] * a;
	return (r);
}

double	*mult_vec_vec(t_vec a, t_vec b, t_vec r)
{
	r[0] = a[0] * b[0];
	r[1] = a[1] * b[1];
	r[2] = a[2] * b[2];
	return (r);
}

double	*add_vec_vec(t_vec a, t_vec b, t_vec r)
{
	r[0] = a[0] + b[0];
	r[1] = a[1] + b[1];
	r[2] = a[2] + b[2];
	return (r);
}

double	*add_vec(t_vec v, double a, t_vec r)
{
	r[0] = v[0] + a;
	r[1] = v[1] + a;
	r[2] = v[2] + a;
	return (r);
}

double	*minus_vec(t_vec v, double a, t_vec r)
{
	r[0] = v[0] - a;
	r[1] = v[1] - a;
	r[2] = v[2] - a;
	return (r);
}
