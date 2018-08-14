/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:09:23 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/14 18:41:32 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

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
	double	invWidth = 1 / 4.;//(double)r->w;
	double	invHeight = 1 / 4.;//(double)r->h;
	double	fov = 80;
	double	aspect_rat = 1;//(r->w) / (double)(r->h);
	double	angle = tan(M_PI * 0.5f * fov / 180.f);
	double	near;
	t_ray	ray;
	double	c[4][4];
	
	new_image(r, 1, -200, 0);
	pos[0] = 0;
	prev_per = -1;
	ft_putstr("Loading... \n[");
	calccam(&r->obj[0]);
	inver(r->obj[0].otw, c);
	for (int i = 0; i < 4; i++)
		printf("C		%lf		%lf		%lf		%lf\n", c[i][0], c[i][1], c[i][2], c[i][3]);
	for (int i = 0; i < 4; i++)
		printf("OTW		%lf		%lf		%lf		%lf\n", r->obj[0].otw[i][0], r->obj[0].otw[i][1], r->obj[0].otw[i][2], r->obj[0].otw[i][3]);
	while (pos[0] < 4)//r->w - 200)
	{
		pos[1] = 0;
		while (pos[1] < 4)//r->h)
		{
			near = INFINITY;
			//TODO: RayStuff
			ray.dir[0] = (2 * ((pos[1] + 0.5) * invWidth) - 1) * angle * aspect_rat;
			ray.dir[1] = (1 - 2 * ((pos[0] + 0.5f) * invHeight)) * angle;
			ray.ori[0] = 0;
			ray.ori[1] = 0;
			ray.ori[2] = 20;
			ray.dir[2] = -1;
			normalise(ray.dir);
			//cast ray
			printf("B::%lf::%lf::%lf		xx::%lf, yy::%lf		%lf\n", ray.dir[0], ray.dir[1], ray.dir[2], pos[0], pos[1], vec_len(ray.dir));
			mult_vec(r->obj[0].otw, ray.dir, ray.dir);
			mult_vec(c, ray.dir, ray.dir);
			printf("A::%lf::%lf::%lf		xx::%lf, yy::%lf		%lf\n\n", ray.dir[0], ray.dir[1], ray.dir[2], pos[0], pos[1], vec_len(ray.dir));
			/* if (100 * (pos[0] + pos[1] * r->w - 200) / (r->w * r->h) > prev_per + 1)
			{
				prev_per = 100 * (pos[0] + pos[1] * r->w - 200) / (r->w * r->h);
				ft_putstr("=");
			} */
			pos[1]++;
		}
		pos[0]++;
	}
	mlx_put_image_to_window(r->mlx, r->win, r->img[1], 200, 0);
	ft_putstr("]\n");
}