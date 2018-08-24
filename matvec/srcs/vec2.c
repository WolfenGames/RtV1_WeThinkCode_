/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 08:16:54 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/24 08:31:26 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/matvec.h"

void	vec_dup(t_vec s, t_vec d)
{
	d[0] = s[0];
	d[1] = s[1];
	d[2] = s[2];
}

void	vec_swap(t_vec a, t_vec b)
{
	t_vec	t;

	vec_dup(a, t);
	vec_dup(b, a);
	vec_dup(t, b);
}

double	*vec_flip(t_vec v, t_vec r)
{
	mult_vec_f(v, -1, r);
	return (r);
}