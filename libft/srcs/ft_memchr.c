/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:25:54 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 10:37:02 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ret;
	size_t			i;

	i = 0;
	ret = (unsigned char *)str;
	while (i < n)
	{
		if (*(ret + i) == (unsigned char)c)
			return (ret + i);
		i++;
	}
	return (NULL);
}
