/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 07:39:38 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/23 15:17:57 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		get_col(char *line)
{
	char	*t;
	int		p;

	t = ft_strmap(line, ft_char_toupper);
	p = ft_atoi_base(t, 16);
	free(t);
	return (p);
}

int		colour_grad(int col1, int col2, float r)
{
	float	b_col1[3];
	float	b_col2[3];
	int		ret;

	b_col1[0] = (col1 & 0xff0000) / 0x10000;
	b_col1[1] = (col1 & 0xff00) / 0x100;
	b_col1[2] = (col1 & 0xff);
	b_col2[0] = (col2 & 0xff0000) / 0x10000;
	b_col2[1] = (col2 & 0xff00) / 0x100;
	b_col2[2] = (col2 & 0xff);
	ret = b_col2[0] * r + b_col1[0] * (1 - r);
	ret *= 0x100;
	ret += b_col2[1] * r + b_col1[1] * (1 - r);
	ret *= 0x100;
	ret += b_col2[2] * r + b_col1[2] * (1 - r);
	return (ret);
}

int		scale_colour(int col1, double r)
{
	double	b_col1[3];
	int		ret;

	b_col1[0] = (col1 & 0xff0000) / 0x10000;
	b_col1[1] = (col1 & 0xff00) / 0x100;
	b_col1[2] = (col1 & 0xff);
	ret = b_col1[0] * r;
	ret *= 0x100;
	ret += b_col1[1] * r;
	ret *= 0x100;
	ret += b_col1[2] * r;
	return (ret);
}