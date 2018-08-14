/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:02:58 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 10:46:10 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	MALLCHECK_N((str = (char *)ft_memalloc(size + 1)));
	ft_memset(str, '\0', size + 1);
	return (str);
}
