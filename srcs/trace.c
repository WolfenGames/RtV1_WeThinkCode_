/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:09:23 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/09 10:43:23 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	ray_hit(float x, float y)
{
	(void)y;
	(void)x;
}

void	info(t_raytrace *r)
{
	double	pos[2];
	
	new_image(r, 2, 0, 800);
	pos[0] = 0;
	while (pos[0] < 200)
	{
		pos[1] = 0;
		while (pos[1] < r->h - 800)
		{
			put_pixel(pos, 2, r, 0x3BAB98);
			pos[1] += .1f;
		}
		pos[0] += .1f;
	}
	mlx_put_image_to_window(r->mlx, r->win, r->img[2], 0, 800);
	mlx_string_put(r->mlx, r->win, 10, 810, 0X18545E,
					"RTv1");
	mlx_string_put(r->mlx, r->win, 10, 840, 0X18545E,
					"jwolf");
	mlx_string_put(r->mlx, r->win, 10, 870, 0X18545E,
					"WeThinkCode_");
}

void	back(t_raytrace *r)
{
	double	pos[2];
	
	new_image(r, 0, 0, 0);
	pos[0] = 0;
	while (pos[0] < r->w)
	{
		pos[1] = 0;
		while (pos[1] < r->h)
		{
			put_pixel(pos, 0, r, 0XF2EFAA);
			pos[1] += .1f;
		}
		pos[0] += .1f;
	}
	mlx_put_image_to_window(r->mlx, r->win, r->img[0], 0, 0);
}

void	trace(t_raytrace *r)
{
	double	pos[2];
	
	new_image(r, 1, -200, 0);
	pos[0] = 0;
	while (pos[0] < r->w - 200)
	{
		pos[1] = 0;
		while (pos[1] < r->h)
		{
			put_pixel(pos, 1, r, 0x18545E);
			//ray_hit(x, y);
			pos[1] += .1f;
		}
		pos[0] += .1f;
	}
	mlx_put_image_to_window(r->mlx, r->win, r->img[1], 200, 0);
}