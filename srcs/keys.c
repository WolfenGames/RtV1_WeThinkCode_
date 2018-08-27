/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 06:24:25 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/27 06:37:49 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		butt(int b, t_raytrace *r)
{
	(void)b;
	(void)r;
	exit(0);
	return (0);
}

int		keys(int key, t_raytrace *r)
{
	if (key == 53)
		butt(0, r);
	return (0);
}

void	set_hooks(t_raytrace *r)
{
	mlx_hook(r->win, 2, 0, keys, r);
	mlx_hook(r->win, 17, 0, butt, r);
	back(r);
	info(r);
	trace(r);
	debug_text(r);
}
