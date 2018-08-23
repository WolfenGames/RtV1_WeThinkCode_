/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:15:27 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/23 14:17:19 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_swap(void *a, void *b, size_t size)
{
	void	*tmp;

	tmp = ft_memalloc(size);
	ft_memmove(tmp, a, size);
	ft_memmove(a, b, size);
	ft_memmove(b, tmp, size);
	free(tmp);
}