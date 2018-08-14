/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 00:48:06 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 10:52:44 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(const char *s1, unsigned int start, size_t len)
{
	int		i;
	char	*substr;

	STRCHECK(s1);
	MALLCHECK_N((substr = (char *)ft_memalloc(len + 1)));
	i = 0;
	while (len--)
	{
		substr[i] = s1[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
