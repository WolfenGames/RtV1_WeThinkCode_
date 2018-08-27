/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 08:17:55 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/27 06:42:24 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/matvec.h"

double	*mult_vec(double a[4][4], double v[3], double r[3])
{
	t_vec temp;

	temp[0] = v[0] * a[0][0] + v[1] * a[1][0] + v[2] * a[2][0];
	temp[1] = v[0] * a[0][1] + v[1] * a[1][1] + v[2] * a[2][1];
	temp[2] = v[0] * a[0][2] + v[1] * a[1][2] + v[2] * a[2][2];
	ft_memmove(r, temp, 3 * sizeof(double));
	return (r);
}

double	*mult_trans(double a[4][4], double v[3], double r[3])
{
	double	cpy[3];

	cpy[0] = v[0] * a[0][0] + v[1] * a[1][0] + v[2] * a[2][0] + a[3][0];
	cpy[1] = v[0] * a[0][1] + v[1] * a[1][1] + v[2] * a[2][1] + a[3][1];
	cpy[2] = v[0] * a[0][2] + v[1] * a[1][2] + v[2] * a[2][2] + a[3][2];
	ft_memmove(r, cpy, 3 * sizeof(double));
	return (r);
}

void	mult_mat(double a[4][4], double b[4][4], double r[4][4])
{
	double	cpy[4][4];
	int		x;
	int		y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			cpy[x][y] = a[x][0] * b[0][y] + a[x][1] * b[1][y] + a[x][2]
				* b[2][y] + a[x][3] * b[3][y];
			y++;
		}
		x++;
	}
	ft_memmove(r, cpy, 16 * sizeof(double));
}

double	angle_find(t_vec a, t_vec b)
{
	t_vec	r;

	r[0] = dot(a, a);
	r[1] = dot(a, b);
	r[2] = dot(b, b);
	return (acos(r[1] / sqrt(r[0] * r[2])));
}
