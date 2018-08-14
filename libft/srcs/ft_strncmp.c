/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:01:07 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 10:41:07 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (0);
	while (*s1 == *s2++ && i < n)
	{
		if (*s1++ == '\0' || i == (n - 1))
			return (0);
		i++;
	}
	return (*(unsigned const char *)s1 - *(unsigned const char *)(s2 - 1));
}
