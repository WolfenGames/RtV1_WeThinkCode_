/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 07:50:52 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/16 11:38:29 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

char    *get_obj_name(t_type i)
{
	if (i == EYE)
		return ("Eye");
	if (i == CAMERA)
		return ("Camera");
	if (i == SPHERE)
		return ("Sphere");
	if (i == LIGHT_SPOT)
		return ("Light Spot");
	if (i == LIGHT_DIR)
		return ("Light Directional");
	if (i == LIGHT_CONE)
		return ("Light Cone");
	if (i == LIGHT_POINT)
		return ("Light Point");
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