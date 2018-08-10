/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:09:23 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/10 11:32:09 by jwolf            ###   ########.fr       */
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

t_vec	tracer(t_ray *r, t_raytrace *rt, int *depth)
{
	float	near;
	float	*t[2];
	t_obj	*o;
	int		i;
	t_vec	surf_col;
	t_vec	phit;
	t_vec	nhit;
	float	bias;
	t_bool	inside;
	float	facingratio;
	float	fresneleffect;
	t_vec	refldir;
	t_vec	reflection;
	t_vec	refraction;

	near = INFINITY;
	i = 0;
	while (rt->obj[i].type > 2)
	{
		*t[0] = INFINITY;
		*t[1] = INFINITY;
		if (intersect_circ(r, rt->obj[i], t[0], t[1]))
		{
			if (t[0] < 0)
				t[0] = t[1];
			if (*t[0] < near)
			{
				near = *t[0];
				*o = rt->obj[i];
			}
		}
		if (!o)
			return ((t_vec){255,255,255, 0});
		surf_col = (t_vec){0, 0, 0, 0};
		phit = mult_vec(add_vec_vec(r->ori, r->dir), near);
		nhit = minus_vec_vec(phit, o->mat[0]);
		nhit = normalise(nhit);
		bias = 1e-4;
		inside = FALSE;
		if (dot(r->dir, nhit) > 0)
		{
			nhit = vec_flip(nhit);
			inside = TRUE;
		}
		if ((o->trans > 0 || o->reflec > 0) && depth < MAX_RAY_DEPTH)
		{
			facingratio = dot(vec_flip(r->dir), nhit);
			fresneleffect = mix(pow(1 - facingratio, 3), 1, 0.1f);
			refldir = minus_vec_vec(r->dir, mult_vec(nhit, dot(r->dir, nhit) * 2));
			refldir = normalise(refldir);
			t_ray	r2;
			r2.ori = mult_vec(add_vec_vec(phit, nhit), bias);
			r2.dir = refldir;
			reflection = tracer(&r2, rt, depth + 1);
			if (o->trans)
			{
				float	ior;
				float	eta;
				float	cosi;
				float	k;

				ior = 1.1;
				eta = (inside) ? ior : 1 / ior;
				cosi = dot(vec_flip(nhit), r->dir);
				k = 1 - eta * eta * (1 - cosi * cosi);
				t_vec	refdir;
				t_ray	r3;

				refdir = mult_vec(add_vec_vec(mult_vec(r->dir, eta), nhit), (eta * cosi - sqrt(k)));
				refdir = normalise(refdir);
				r3.ori = mult_vec(add_vec_vec(phit, nhit), bias);
				r3.dir = refldir;
				refraction = tracer(&r3, rt, depth + 1);
			}
			surf_col = mult_vec_vec(add_vec_vec((mult_vec(reflection, fresneleffect)),
						mult_vec(refraction, (1 - fresneleffect))), mult_vec(o->surface_col, o->trans));
		}else
		{

		}
	}
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