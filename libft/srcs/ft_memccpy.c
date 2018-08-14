/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:09:28 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 10:36:27 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;

	i = 0;
	dest = (unsigned char *)str1;
	src = (unsigned char *)str2;
	while (i < n)
	{
		*(dest + i) = *(src + i);
		if (src[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
