/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:33:07 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 10:37:33 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned const char	*s1;
	unsigned const char	*s2;

	s1 = (unsigned const char *)str1;
	s2 = (unsigned const char *)str2;
	while (n-- != 0)
		if (*s1++ != *s2++)
			return (*--s1 - *--s2);
	return (0);
}
