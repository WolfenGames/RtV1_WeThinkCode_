/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:27:24 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 10:54:30 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = 0;
	STRCHECK(s);
	i = ft_strlen((char *)s);
	while (s && *(s + start) && IS_SPACE(*(s + start)))
		start++;
	while (s && end < i && IS_SPACE(*(s + i - 1 - end)))
		end++;
	if ((int)(i - end - start) < 0)
		return (ft_strsub(s, start, 0));
	return (ft_strsub(s, start, i - end - start));
}
