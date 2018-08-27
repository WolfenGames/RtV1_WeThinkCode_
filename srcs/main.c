/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:18:45 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/27 07:36:40 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	valid_scene(t_raytrace *r)
{
	if (r->objsize == 1)
	{
		ft_putendl("I work better with more than a Camera...");
	}
}

void	create_objects(char *file, t_raytrace *r)
{
	int			fd;

	r->obj = (t_obj *)malloc(sizeof(t_obj) * 2);
	r->obj[0].name = "Camera";
	r->obj[0].type = CAMERA;
	r->obj[1].name = "Light";
	r->obj[1].type = LIGHT;
	r->objsize = 2;
	if (!ft_strequ(ft_strchr(file, '.'), ".rtv1"))
	{
		ft_putendl("Shit is invalid");
		exit(1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl("Shit is invalid");
		exit(1);
	}
	load_file(fd, r);
	close(fd);
	valid_scene(r);
}

int		main(int ac, char **av)
{
	t_raytrace	r;

	if (ac == 2)
	{
		r.w = 1000;
		r.h = 800;
		r.mlx = mlx_init();
		r.win = mlx_new_window(r.mlx, r.w, r.h, "RTv1");
		r.img = (void **)malloc(sizeof(void *) * 3);
		r.data = (void **)malloc(sizeof(void *) * 3);
		create_objects(av[1], &r);
		set_hooks(&r);
		mlx_loop(r.mlx);
	}
	else
	{
		ft_putendl("FEED ME FILES!");
		exit(0);
	}
	return (0);
}
