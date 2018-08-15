/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:09:23 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/15 16:18:01 by jwolf            ###   ########.fr       */
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

t_bool	quad(double a, double b, double c, double d[2])
{
	double	e;
	double	hold;

	e = b * b - 4.0f * a * c;
	if (e < 0)
		return (FALSE);
	if (e == 0)
	{
		d[1] = -0.5f * b / a;
		d[0] = d[1];
	}
	else
	{
		hold = (b > 0) ? (-0.5f * b + sqrt(e)) : (-0.5f * b - sqrt(e));
		d[0] = hold / a;
		d[1] = c / hold;
	}
	if (d[0] > d[1])
	{
		hold = d[0];
		d[0] = d[1];
		d[1] = hold;
	}
	return (TRUE);
}

int		tracer(t_ray ray, t_obj *obj, double n)
{
	t_vec	l;
	double	a[3];
	double	inter[2];

	minus_vec_vec(ray.ori, obj[3].ori, l);
	a[0] = dot(ray.dir, ray.dir);
	a[1] = 2 * dot(ray.dir, l);
	a[2] = dot(l, l) - obj[3].radius2;
//	printf("QUAD A::%lf		B::%lf		C::%lf\n", a[0], a[1], a[2]);
	if (!quad(a[0], a[1], a[2], inter))
		return(0);
//	printf("INTERS 1::%lf		2::%lf\n", inter[0], inter[1]);
	if (inter[0] < 0)
		inter[0] = inter[1];
	if (inter[0] < 0)
		return (0);//xFF0000);
	n = inter[0];
	return (0xFF0000);
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
	double	invWidth = 1 / ((double)r->w - 200);
	double	invHeight = 1 / (double)r->h;
	double	fov = 80;
	double	aspect_rat = (r->w - 200) / (double)(r->h);
	double	angle = tan(M_PI * 0.5f * fov / 180.f);
	double	near;
	t_ray	ray;
//	double	c[4][4];
	
	new_image(r, 1, -200, 0);
	pos[0] = 0;
	prev_per = -1;
	ray.ori[0] = r->obj[0].ori[0];
	ray.ori[1] = r->obj[0].ori[1];
	ray.ori[2] = r->obj[0].ori[2];
	ft_putstr("Loading... \n[");
	calccam(&r->obj[0]);
	/* for (int i = 0; i < 3; i++)
		printf("%lf		%lf		%lf\n", r->obj[0].otw[i][0], r->obj[0].otw[i][1], r->obj[0].otw[i][2]); */
	while (pos[0] < r->w - 200)
	{
		pos[1] = 0;
		while (pos[1] < r->h)
		{
			near = INFINITY;
			//TODO: RayStuff
			ray.dir[0] = (2 * (pos[0] + 0.5) * invWidth - 1) * angle * aspect_rat;
			ray.dir[1] = (1 - 2 * ((pos[1] + 0.5f) * invHeight)) * angle;
			ray.dir[2] = -1;
			mult_vec(r->obj[0].otw, ray.dir, ray.dir);
			//printf("A::%lf		%lf		%lf\n\n", ray.dir[0], ray.dir[1], ray.dir[2]);
			normalise(ray.dir);
			put_pixel(pos, SCREEN, r, tracer(ray, r->obj, near));
			//cast ray/
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