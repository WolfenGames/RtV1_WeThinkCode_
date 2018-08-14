/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:18:45 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/14 16:55:51 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		update(t_raytrace *r)
{
	trace(r);
	return (0);
}

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

void	create_objects(t_raytrace *r)
{
	r->obj = (t_obj *)malloc(sizeof(t_obj) * 5);
	r->obj[0].type = CAMERA;
	r->obj[0].ori[0] = 0;
	r->obj[0].ori[1] = 0;
	r->obj[0].ori[2] = 20;
	r->obj[0].rot[0] = 90;
	r->obj[1].type = EYE;
	r->obj[2].type = LIGHT_DIR;
	r->obj[3].type = SPHERE;
	r->obj[4].type = SPHERE;
	r->objsize = 5;
}

int		main(void)
{
	t_raytrace	*r;

	r = (t_raytrace *)malloc(sizeof(t_raytrace));
	r->w = 1100;
	r->h = 900;
	r->mlx = mlx_init();
	r->win = mlx_new_window(r->mlx, r->w, r->h, "RTv1");
	r->img = (void **)malloc(sizeof(void *) * 3);
	r->data = (void **)malloc(sizeof(void *) * 3);
	create_objects(r);
	set_hooks(r);
	mlx_loop(r->mlx);
	return (0);
}
