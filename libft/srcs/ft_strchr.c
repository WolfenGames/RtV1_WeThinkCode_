/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:05:14 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/18 07:21:56 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*s1;

	i = 0;
	s1 = (char *)str;
	while (*(s1 + i) && *(s1 + i) != (char)c)
		i++;
	if (*(s1 + i) == (char)c)
		return (((char *)s1 + i));
	else
		return (NULL);
}
