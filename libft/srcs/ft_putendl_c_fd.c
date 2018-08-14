/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_c_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 07:14:50 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/11 09:20:15 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putendl_c_fd(char const *dest, char const *str, int fd)
{
	if (dest && str)
		ft_putendl_fd(ft_strjoin(dest, str), fd);
	else if (!str)
		ft_putendl_fd(ft_strjoin(dest, "No string passed"), fd);
}
