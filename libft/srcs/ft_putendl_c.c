/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 07:14:50 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/11 09:20:15 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putendl_c(char const *dest, char const *str)
{
	char	*temp;

	temp = NULL;
	if (dest && str)
	{
		temp = ft_strjoin(dest, str);
		ft_putendl(temp);
		free(temp);
	}
	else if (!str)
	{
		temp = ft_strjoin(dest, "No string passed");
		ft_putendl(temp);
		free(temp);
	}
}
