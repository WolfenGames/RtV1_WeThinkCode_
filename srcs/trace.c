/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:09:23 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/23 08:26:12 by jwolf            ###   ########.fr       */
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

int		inter_plane(t_ray ray, t_obj obj, double *n)
{
	t_ray	nr;
	double	a;

	mult_vec(obj.wto, ray.dir, nr.dir);
	mult_trans(obj.wto, ray.org, nr.org);
 	if (!((nr.org[1] < 0 && nr.dir[1] > 0) || (nr.org[1] > 0 && nr.dir[1] < 0)))
		return (0);
	normalise(nr.dir);
	a = ABS(nr.org[1] / (nr.dir[1] - 0.0001));
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
	mult_trans(obj.wto, ray.org, nr.org);
	minus_vec_vec(nr.org, obj.org, l);
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
	double	a[3];
	double	inter[2];
	t_ray	nr;

	mult_vec(obj.wto, ray.dir, nr.dir);
	mult_trans(obj.wto, ray.org, nr.org);
	//minus_vec_vec(nr.org, obj.org, l);
	a[0] = dot(nr.dir, nr.dir);
	a[1] = 2 * dot(nr.dir, nr.org);
	a[2] = dot(nr.org, nr.org) - obj.radius2;
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
			if (inter_cone(ray, r->obj[x], &n))
				col = x;
		if (r->obj[x].type == CYLINDER)
			if (inter_cylinder(&ray, &r->obj[x], &n))
				col = x;
		if (r->obj[x].type == PLANE)
			if (inter_plane(ray, r->obj[x], &n))
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

void    trace_stuff(t_ray ray, double invVal, double ang, t_raytrace *r)
{
	double	pos[2];
	double	near;

	pos[0] = 0;
	while (pos[0] < 800)
	{
		pos[1] = 0;
		while (pos[1] < 800)
		{
			near = INFINITY;
			ray.dir[0] = (2 * (pos[0] + 0.5f) * invVal - 1) * ang;
			ray.dir[1] = (1 - 2 * ((pos[1] + 0.5f) * invVal)) * ang;
			ray.dir[2] = -1;
			transformvec(CAM.otw, ray.dir, ray.dir);
			normalise(ray.dir);
			put_pixel(pos, SCREEN, r, tracer(ray, r, near));
			pos[1]++;
		}
		pos[0]++;
	}
}

void	trace(t_raytrace *r)
{
	double	invVal;
	double	angle;
	t_ray	ray;
	
	new_image(r, SCREEN, -200, 0);
	ft_memcpy(ray.org, CAM.org, 3 * sizeof(double));
	calccam(&CAM);
	invVal = 1 / ((double)800);
	angle = tan(M_PI * 0.5f * CAM.fov / 180.f);
	trace_stuff(ray, invVal, angle, r);
	mlx_put_image_to_window(r->mlx, r->win, r->img[SCREEN], 200, 0);
	mlx_destroy_image(r->mlx, r->img[SCREEN]);
}