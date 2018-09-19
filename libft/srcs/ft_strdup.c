/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:47:34 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 10:38:08 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	i;
	size_t	f;

	f = ft_strlen((char *)s1);
	i = 0;
	MALLCHECK_N((ret = (char *)ft_memalloc(sizeof(char) * (f + 1))));
	ret = ft_strcpy(ret, s1);
	return (ret);
}
