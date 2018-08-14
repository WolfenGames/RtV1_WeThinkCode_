/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 11:19:27 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 10:54:48 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		**ft_strsplit(const char *s, char c)
{
	char	**ret;
	size_t	start;
	size_t	end;
	int		i;

	start = 0;
	end = 0;
	i = 0;
	MALLCHECK_N((s || c));
	if (!(ret = (char **)ft_memalloc(sizeof(ret) * ft_wordcount(s, c) + 1)))
		return (NULL);
	while (ft_wordcount(s, c) - i)
	{
		while (s && *(s + start) && *(s + start) == c)
			start++;
		while (s && *(s + start + end) && *(s + start + end) != c)
			end++;
		ret[i] = ft_strsub(s, start, end);
		start += end;
		end = 0;
		i++;
	}
	ret[i] = 0;
	return (ret);
}
