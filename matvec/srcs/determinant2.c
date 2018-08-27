/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 08:19:39 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/27 06:38:50 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/matvec.h"

void	transpose(double a[4][4], double fac[4][4], double size)
{
	int		i;
	int		j;
	double	d;

	i = -1;
	d = determinant(a, size);
	if (d != 0)
		while (++i < size)
		{
			j = -1;
			while (++j < size)
			{
				a[i][j] = fac[j][i] / d;
			}
		}
}

void	cofactor(double a[4][4], double size)
{
	t_matrix	b;
	t_matrix	fac;
	int			dim[2];

	dim[0] = -1;
	while (++dim[0] < size)
	{
		dim[1] = -1;
		while (++dim[1] < size)
		{
			calco(a, b, size, dim);
			fac[dim[0]][dim[1]] = pow(-1, dim[0] + dim[1])
				* determinant(b, size - 1);
		}
	}
	transpose(a, fac, size);
}
