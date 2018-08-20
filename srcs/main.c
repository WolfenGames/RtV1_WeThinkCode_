/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:18:45 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/17 13:33:06 by jwolf            ###   ########.fr       */
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
	int			fd;

	r->obj = (t_obj *)malloc(sizeof(t_obj));
	r->obj[0].name = "Camera";
	r->obj[0].type = CAMERA;
	r->objsize = 1;
	fd = open("scene/ex.rtv1", O_RDONLY);
	load_file(fd, r);
	close(fd);
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
