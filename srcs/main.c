/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:18:45 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/23 10:30:47 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		update(t_raytrace *r)
{
 	t_matrix m;

	fill_m_rot_x(m, 1 * M_PI / 180.0);
	transform(m, r->obj[0].org, r->obj[0].org);
	r->obj[0].rot[0] += 10;
		calccam(&CAM);
    obj_thingies(r->obj);
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
//	mlx_loop_hook(r->mlx, update, r);
	back(r);
	info(r);
	trace(r);
	debug_text(r);
}

void    valid_scene(t_raytrace *r)
{
    if (r->objsize == 1)
    {
        ft_putendl("I work better with more than a Camera...");
    }    
}

void	create_objects(char *file, t_raytrace *r)
{
	int			fd;

	r->obj = (t_obj *)malloc(sizeof(t_obj));
	r->obj[0].name = "Camera";
	r->obj[0].type = CAMERA;
	r->objsize = 1;
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
	t_raytrace	*r;

    if (ac == 2)
    {
        r = (t_raytrace *)malloc(sizeof(t_raytrace));
        r->w = 1000;
        r->h = 800;
        r->mlx = mlx_init();
        r->win = mlx_new_window(r->mlx, r->w, r->h, "RTv1");
        r->img = (void **)malloc(sizeof(void *) * 3);
        r->data = (void **)malloc(sizeof(void *) * 3);
        create_objects(av[1], r);
        set_hooks(r);
        mlx_loop(r->mlx);
    }
    else
    {
        ft_putendl("FEED ME FILES!");
        exit(0);
    }
	return (0);
}
