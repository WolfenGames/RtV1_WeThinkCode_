/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:53:00 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 11:13:48 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		len;
	int		i;
	char	*c1;
	char	*c2;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	MALLCHECK_N((str = (char *)ft_memalloc(len + 1)));
	c1 = (char *)s1;
	c2 = (char *)s2;
	while (*c1)
		str[++i] = *c1++;
	while (*c2)
		str[++i] = *c2++;
	str[++i] = '\0';
	return (str);
}
