/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 09:48:08 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 10:38:56 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	o;
	size_t	i;

	o = 0;
	i = ft_strlen(dest);
	while (*(src + o))
	{
		*(dest + i) = *(src + o);
		i++;
		o++;
	}
	*(dest + i) = '\0';
	return (dest);
}
