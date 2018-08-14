/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:01:07 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 10:40:51 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2++)
	{
		if (*s1++ == '\0')
			return (0);
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)(s2 - 1));
}
