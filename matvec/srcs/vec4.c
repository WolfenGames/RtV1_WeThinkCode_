/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 08:20:53 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/27 06:44:00 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/matvec.h"

double	*minus_vec_vec(t_vec a, t_vec b, t_vec r)
{
	r[0] = a[0] - b[0];
	r[1] = a[1] - b[1];
	r[2] = a[2] - b[2];
	return (r);
}

void	inver(t_matrix src, t_matrix ret)
{
	t_matrix	a;

	m4_dup(src, a);
	cofactor(a, 4);
	m4_dup(a, ret);
}

int		quad(t_vec co, double t[2])
{
	double discr;
	double q;

	discr = co[1] * co[1] - 4.f * co[0] * co[2];
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		t[1] = -0.5 * co[1] / co[0];
		t[0] = t[1];
	}
	else
	{
		q = (co[1] > 0) ? -0.5 * (co[1] + sqrt(discr)) : -0.5 *
			(co[1] - sqrt(discr));
		t[0] = q / co[0];
		t[1] = co[2] / q;
	}
	if (t[0] > t[1])
		ft_swap(&t[0], &t[1], sizeof(double));
	return (1);
}
