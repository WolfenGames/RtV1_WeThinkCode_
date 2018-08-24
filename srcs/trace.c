/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:09:23 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/24 06:57:23 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

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

int		quad(t_vec co, double t[2])
{
	double discr;
	double q;

	discr = co[1] * co[1] - 4.f * co[0] * co[2];
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		t[1] = -0.5 * co[1] / co[0];
		t[0] = t[1];
	}
	else
	{
		q = (co[1] > 0) ? -0.5 * (co[1] + sqrt(discr)) : -0.5 * (co[1] - sqrt(discr));
		t[0] = q / co[0];
		t[1] = co[2] / q;
	}
	if (t[0] > t[1])
		ft_swap(&t[0], &t[1], sizeof(double));
	return (1);
}

int		inter_sphere(t_ray *ray, t_obj *obj, double *n)
{
	t_vec	l;
	t_vec	v;
	double	t[2];

	minus_vec_vec(ray->org, obj->org, l);
	v[0] = dot(ray->dir, ray->dir);
	v[1] = 2 * dot(l, ray->dir);
	v[2] = dot(l, l) - obj->radius2;
	if (!quad(v, t))
		return (0);
	if (t[0] < 0)
		t[0] = t[1];
	if (t[0] < 0)
		return (0);
	if (t[0] > *n)
		return (0);
	*n = t[0];
	return (1);
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
		x++;
	}
	return (col);
}

int		do_da_ray(double pos[], t_raytrace *r)
{
	t_ray	ray;
	double	inv;
	double	ang;
	double	n;
	t_vec   norm;
	int		objindex;

	inv = 1 / 800.f;
	n = INFINITY;
	ang = tan(CAMFOV * 0.5f * M_PI / 180.0);
	ray.dir[0] = (2 * (pos[0] + 0.5f) * inv - 1) * ang;
	ray.dir[1] = (1 - 2 * (pos[1] + 0.5f) * inv) * ang;
	ray.dir[2] = -1;
	vec_dup(CAM.org, ray.org);
	normalise(ray.dir);
	if ((objindex = obj_index(r, &ray, &n)) == -1)
		return (0);
	mult_vec_f(ray.dir, n, ray.dir);
	add_vec_vec(ray.dir, ray.org, ray.org);
	minus_vec_vec(ray.org, r->obj[objindex].org, norm);
	normalise(norm);
	add_vec_vec(ray.org, mult_vec_f(norm, 0.0001, norm), ray.org);
	minus_vec_vec(LSO, ray.org, ray.dir);
	n = vec_len(ray.dir);
	normalise(ray.dir);
	if (obj_index(r, &ray, &n) != -1)
		return (scale_colour(r->obj[objindex].surface_col, 0.07));
	minus_vec_vec(ray.org, r->obj[objindex].org, norm);
	normalise(norm);
	return (colour_grad(scale_colour(r->obj[objindex].surface_col, dot(norm, ray.dir)), r->obj[objindex].surface_col, 0.07));
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
