/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 07:50:52 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/24 09:10:58 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char    *get_obj_name(t_type i)
{
	if (i == EYE)
		return ("Eye");
	if (i == CAMERA)
		return ("Camera");
	if (i == SPHERE)
		return ("Sphere");
	if (i == LIGHT)
		return ("Light");
	if (i == PLANE)
		return ("Plane");
	if (i == CONE)
		return ("Cone");
    if (i == CYLINDER)
        return ("Cylinder");
	return ("Not Defined");
}

char		ft_char_toupper(char c)
{
	int		ic;

	ic = ft_toupper(c);
	return (ic);
}

char		ft_char_tolower(char c)
{
	int		ic;

	ic = ft_tolower(c);
	return (ic);
}