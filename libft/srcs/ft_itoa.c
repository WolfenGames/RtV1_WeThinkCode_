/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:29:59 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 10:55:06 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_charcount(long n)
{
	size_t	i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	long	l;
	size_t	cnt;
	char	*str;
	int		neg;

	l = n;
	neg = (l < 0) ? 1 : 0;
	cnt = ft_charcount(l);
	str = ft_strnew(cnt + neg);
	STRCHECK(str);
	if (neg)
	{
		l = -l;
		str[0] = '-';
	}
	while (cnt > 0)
	{
		str[cnt + neg - 1] = (l % 10) + '0';
		cnt--;
		l /= 10;
	}
	return (str);
}
