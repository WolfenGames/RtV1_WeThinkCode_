/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:09:23 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/21 06:53:52 by jwolf            ###   ########.fr       */
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

int		inter_plane(t_ray *ray, t_obj *obj, double *n)
{
	t_ray	nr;
	double	a;

	mult_vec(obj->wto, ray->dir, nr.dir);
	mult_trans(obj->wto, ray->ori, nr.ori);
 	if (!((nr.ori[1] < 0 && nr.dir[1] > 0) || (nr.ori[1] > 0 && nr.dir[1] < 0)))
		return (0);
	normalise(nr.dir);
	a = ABS(nr.ori[1] / (nr.dir[1] - 0.0001));
	if (a > *n)
		return (0);
	*n = a;
	return (1);
}

/* int		inter_cylinder(t_ray ray, t_obj obj, double *n)
{
	t_vec	l;
	double	a[3];
	double	inter[2];
	t_ray	nr;

	mult_vec(obj.wto, ray.dir, nr.dir);
	mult_trans(obj.wto, ray.ori, nr.ori);
	minus_vec_vec(nr.ori, obj.ori, l);
	a[0] = dot(nr.dir, nr.dir);
	a[1] = 2 * dot(nr.dir, l);
	a[2] = dot(l, l) - obj.radius2;
 	if (!quad(a[0], a[1], a[2], inter))
		return(0);
	if (inter[0] < 0)
		inter[0] = inter[1];
	if (inter[0] < 0)
		return(0);
	if (inter[0] > *n)
		return (0);
	*n = inter[0];
	return (1);
} */

int		inter_sphere(t_ray ray, t_obj obj, double *n)
{
	t_vec	l;
	double	a[3];
	double	inter[2];
	t_ray	nr;

	mult_vec(obj.wto, ray.dir, nr.dir);
	mult_trans(obj.wto, ray.ori, nr.ori);
	minus_vec_vec(nr.ori, obj.ori, l);
	a[0] = dot(nr.dir, nr.dir);
	a[1] = 2 * dot(nr.dir, l);
	a[2] = dot(l, l) - obj.radius2;
 	if (!quad(a[0], a[1], a[2], inter))
		return(0);
	if (inter[0] < 0)
		inter[0] = inter[1];
	if (inter[0] < 0)
		return(0);
	if (inter[0] > *n)
		return (0);
	*n = inter[0];
	return (1);
}

int		tracer(t_ray ray, t_raytrace *r, double n)
{
	int		x;
	int		col;

	x = 1;
	col = -1;
	while (x < r->objsize)
	{
		if (r->obj[x].type == SPHERE)
			if (inter_sphere(ray, r->obj[x], &n))
				col = x;
		if (r->obj[x].type == CONE)
			if (inter_cone(&ray, &r->obj[x], &n))
				col = x;
		if (r->obj[x].type == CYLINDER)
			if (inter_cylinder(&ray, &r->obj[x], &n))
				col = x;
		if (r->obj[x].type == PLANE)
			if (inter_plane(&ray, &r->obj[x], &n))
				col = x;
		x++;
	}
	return (col < 0 ? (0) : r->obj[col].surface_col);
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
	double	aspect_rat = (r->w - 200) / (double)(r->h);
	double	angle = tan(M_PI * 0.5f * r->obj[0].fov / 180.f);
	double	near;
	t_ray	ray;
	
	new_image(r, 1, -200, 0);
	pos[0] = 0;
	prev_per = -1;
	ray.ori[0] = r->obj[0].ori[0];
	ray.ori[1] = r->obj[0].ori[1];
	ray.ori[2] = r->obj[0].ori[2];
	calccam(&r->obj[0]);
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
			normalise(ray.dir);
			put_pixel(pos, SCREEN, r, tracer(ray, r, near));
			pos[1]++;
		}
		pos[0]++;
	}
	mlx_put_image_to_window(r->mlx, r->win, r->img[1], 200, 0);
}