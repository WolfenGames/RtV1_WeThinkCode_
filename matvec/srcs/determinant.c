/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 08:18:23 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/24 08:32:12 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/matvec.h"

void	calco(double a[4][4], double b[4][4], double size, int dim[2])
{
	int		i[4];

	i[3] = 0;
	i[2] = 0;
	i[0] = -1;
	while (++i[0] < size)
	{
		i[1] = -1;
		while (++i[1] < size)
		{
			if (i[0] != dim[0] && i[1] != dim[1])
			{
				b[i[3]][i[2]] = a[i[0]][i[1]];
				if (i[2] < (size - 2))
					i[2]++;
				else
				{
					i[2] = 0;
					i[3]++;
				}
			}
		}
	}
}

static void	det_work(t_matrix a, t_matrix b, double size, int c)
{
	int	i[4];

	i[2] = 0;
	i[3] = 0;
	i[0] = -1;
	while (++i[0] < size)
	{
		i[1] = -1;
		while (++i[1] < size)
		{
			b[i[0]][i[1]] = 0;
			if (i[0] != 0 && i[1] != c)
			{
				b[i[2]][i[3]] = a[i[0]][i[1]];
				if (i[3] < (size - 2))
					i[3]++;
				else
				{
					i[3] = 0;
					i[2]++;
				}
			}
		}
	}
}

double		determinant(t_matrix a, double size)
{
	double		s;
	double		ret;
	t_matrix	b;
	int			c;

	s = 1;
	ret = 0;
	if (size == 1)
		return (a[0][0]);
	c = -1;
	while (++c < size)
	{
		det_work(a, b, size, c);
		ret = ret + s * (a[0][c] * determinant(b, size - 1));
		s = -1 * s;
	}
	return (ret);
}


void		m4_dup(t_matrix src, t_matrix ret)
{
	int i;
	int j;

	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
			ret[i][j] = src[i][j];
	}
}