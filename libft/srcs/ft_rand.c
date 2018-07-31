/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 06:16:51 by jwolf             #+#    #+#             */
/*   Updated: 2018/07/19 07:25:06 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_rand(int min, int max, int seed)
{
	int		i;
	int		cpy;
	int		num;
	int		res;

	i = 0;
	res = 0;
	num = (long)malloc(sizeof(long));
	if (num < 0)
		num = -num;
	cpy = num;
	while (num >= 10)
	{
		res += (num % 10);
		num /= 10;
		i++;
	}
	res = res * seed + cpy + i;
	res = ((res % (max + 1)) + min);
	return (res);
}
