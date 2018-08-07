/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:31:00 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/07 14:35:16 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_vec   trace(t_vec o_ray, t_ray r, t_obj obj, int depth)
{
	float	tnear = INFINITY;
	t_obj	o;
	int		t[2] = {INFINITY, INFINITY};
	if (intersects(obj, o_ray, r, t))
	{
		if (t[0] < t[1])
			t[0] = t[1];
		if (t[0] < tnear)
		{
			tnear = 0;
			o = obj;
		}
	}
}