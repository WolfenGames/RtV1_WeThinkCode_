/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 07:36:55 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/24 08:35:06 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

double				ft_atod(const char *str)
{
	size_t	i;
	int		num;
	double	num2;
	t_bool	neg;
	char	**side;

	i = 0;
	num = 0;
	neg = FALSE;
	side = ft_strsplit(str, '.');
	num = ft_atoi(side[0]);
	if (side[1])
	{
		num2 = ft_atoi(side[1]);
		while (num2 > 1)
			num2 /= 10.0;
		free(side[1]);
	}
	free(side[0]);
	free(side);
	if (!side[1])
		return ((double)num);
	return ((double)(num + num2));
}
