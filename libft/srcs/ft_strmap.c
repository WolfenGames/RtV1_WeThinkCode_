/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:14:53 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 10:49:24 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char		*str;
	int			i;
	int			j;

	if (s && f)
	{
		i = 0;
		j = ft_strlen((char *)s);
		MALLCHECK_N((str = (char *)ft_memalloc(j + 1)));
		while (s[i])
		{
			str[i] = f(s[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
