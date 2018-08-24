/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:09:23 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/24 12:56:05 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	info(t_raytrace *r)
{
	double	pos[2];

	new_image(r, 2, -800, 800);
	pos[0] = 0;
	while (pos[0] < 200)
	{
		pos[1] = 0;
		while (pos[1] < r->h - 700)
		{
			put_pixel(pos, 2, r, 0x3BAB98);
			pos[1] += .1f;
		}
		pos[0] += .1f;
	}
	mlx_put_image_to_window(r->mlx, r->win, r->img[2], 0, 700);
	mlx_string_put(r->mlx, r->win, 10, 710, 0X18545E,
			"RTv1");
	mlx_string_put(r->mlx, r->win, 10, 740, 0X18545E,
			"jwolf");
	mlx_string_put(r->mlx, r->win, 10, 770, 0X18545E,
			"WeThinkCode_");
}

void	back(t_raytrace *r)
{
	double	pos[2];

	new_image(r, 0, -800, 0);
	pos[0] = 0;
	while (pos[0] < 200)
	{
		pos[1] = 0;
		while (pos[1] < 700)
		{
			put_pixel(pos, 0, r, 0XF2EFAA);
			pos[1] += .1f;
		}
		pos[0] += .1f;
	}
	mlx_put_image_to_window(r->mlx, r->win, r->img[0], 0, 0);
}

int     obj_index(t_raytrace *r, t_ray *ray, double *n)
{
	int     x;
	int		col;

	col = -1;
	x = 2;
	while (x < r->objsize)
	{
		if (r->obj[x].type == SPHERE)
			if (inter_sphere(ray, &r->obj[x], n))
				col = x;
		if (r->obj[x].type == PLANE)
			if (inter_plane(ray, &r->obj[x], n))
				col = x;
		if (r->obj[x].type == CONE)
			if (inter_cone(ray, &r->obj[x], n))
				col = x;
		if (r->obj[x].type == CYLINDER)
			if (inter_cylinder(ray, &r->obj[x], n))
				col = x;
		x++;
	}
	return (col);
}

int		lightstuff(t_obj *o, t_raytrace *r)
{
	t_ray	ray;
	t_vec	tmp;
	double	n;

	vec_dup(o->point, ray.org);
	minus_vec_vec(LSO, ray.org, ray.dir);
	n = vec_len(ray.dir);
	normalise(ray.dir);
	add_vec_vec(ray.org, mult_vec_f(o->norm, 0.000000001, tmp), ray.org);
	if (obj_index(r, &ray, &n) != -1)
		return (scale_colour(o->surface_col, 0.07));
	return (maxd(scale_colour((colour_grad(scale_colour(o->surface_col, mind(dot(o->norm, ray.dir), 1.0)),
		o->surface_col, 0.07)), mind(LI / n, 1.0)), scale_colour(o->surface_col, 0.07)));
}

int		do_da_ray(double pos[], t_raytrace *r)
{
	t_ray	ray;
	double	inv;
	double	ang;
	double	n;
	int		oi;

	inv = 1 / 800.f;
	n = INFINITY;
	ang = tan(CAMFOV * 0.5f * M_PI / 180.0);
	ray.dir[0] = (2 * (pos[0] + 0.5f) * inv - 1) * ang;
	ray.dir[1] = (1 - 2 * (pos[1] + 0.5f) * inv) * ang;
	ray.dir[2] = -1;
	mult_vec(CAM.otw, ray.dir, ray.dir);
	vec_dup(CAM.org, ray.org);
	normalise(ray.dir);
	if ((oi = obj_index(r, &ray, &n)) == -1)
		return (0);
	return (lightstuff(&r->obj[oi], r));
}

void	tracer(t_raytrace *r)
{
	double	pos[2];

	pos[0] = 0;
	while (pos[0] < 800)
	{
		pos[1] = 0;
		while (pos[1] < 800)
		{
			put_pixel(pos, SCREEN, r, 
					do_da_ray(pos, r));
			pos[1]++;
		}
		pos[0]++;
	}
}

void	trace(t_raytrace *r)
{
	new_image(r, SCREEN, -200, 0);
	tracer(r);
	mlx_put_image_to_window(r->mlx, r->win, r->img[SCREEN], 200, 0);
	mlx_destroy_image(r->mlx, r->img[SCREEN]);
}
