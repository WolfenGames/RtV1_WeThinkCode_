/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:23:22 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 11:03:20 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrimcpy(char *ret, const char *s, int start, int end)
{
	int		c;

	c = 0;
	MALLCHECK_N((ret || s));
	while (start <= end)
	{
		ret[c] = s[start];
		start++;
		c++;
	}
	ret[c] = '\0';
	return (ret);
}
