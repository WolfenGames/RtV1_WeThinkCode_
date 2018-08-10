/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:09:23 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/10 10:14:01 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	ray_hit(float x, float y)
{
	(void)y;
	(void)x;
}

t_bool intersect_circ(t_ray *r, t_obj o, float *a, float *b)
{
	t_vec	l;
	float	tca;
	float	thc;
	float	d2;

	o.radius = o.mat[3].w;
	o.radius2 = o.radius * o.radius;
	l = minus_vec_vec(o.mat[3], r->ori);
	tca = dot(l, r->dir);
	if (tca < 0)
		return (FALSE);
	d2 = dot(l, l) - tca * tca;
	if (d2 > (o.radius2))
		return (FALSE);
	thc = sqrt(o.radius2 - d2);
	*a = tca - thc;
	*b = tca + thc;
	return (TRUE);
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
	int		prev_per;
	
	new_image(r, 1, -200, 0);
	pos[0] = 0;
	prev_per = -1;
	ft_putstr("Loading... \n[");
	while (pos[0] < r->w - 200)
	{
		pos[1] = 0;
		while (pos[1] < r->h)
		{
			//TODO: RayStuff
			if (50 * (pos[0] + pos[1] * r->w - 200) / (r->w * r->h) > prev_per + 1)
			{
				prev_per = 50 * (pos[0] + pos[1] * r->w - 200) / (r->w * r->h);
				ft_putstr("=");
			}
			pos[1] += .1f;
		}
		pos[0] += .1f;
	}
	mlx_put_image_to_window(r->mlx, r->win, r->img[1], 200, 0);
	ft_putstr("]\n");
}