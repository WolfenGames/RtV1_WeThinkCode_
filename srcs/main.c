/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:18:45 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/09 11:11:55 by jwolf            ###   ########.fr       */
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

/*
**  t_vecs -> x, y, z, w;
*/

void	create_objects(t_raytrace *r)
{
	r->obj = (t_obj *)malloc(sizeof(t_obj) * 5);
	r->obj[0].type = CAMERA;
	r->obj[0].mat[0] = (t_vec){0, 0, 0, 0};
	r->obj[0].mat[1] = (t_vec){0, 0, 0, 0};
	r->obj[0].mat[2] = (t_vec){0, 0, 0, 0};
	r->obj[0].mat[3] = (t_vec){0, 0, 0, 0};
	r->obj[1].type = EYE;
	r->obj[1].mat[0] = (t_vec){20, 20, 0, 0};
	r->obj[1].mat[1] = (t_vec){0, 0, 0, 0};
	r->obj[1].mat[2] = (t_vec){0, 0, 0, 0};
	r->obj[1].mat[3] = (t_vec){0, 0, 0, 0};
	r->obj[2].type = LIGHT_DIR;
	r->obj[2].mat[0] = (t_vec){0, 0, 0, 0};
	r->obj[2].mat[1] = (t_vec){0, 0, 0, 0};
	r->obj[2].mat[2] = (t_vec){0, 0, 0, 0};
	r->obj[2].mat[3] = (t_vec){0, 90, 0, 0};
	r->obj[3].type = SPHERE;
	r->obj[3].mat[0] = (t_vec){0, 10, 0, 0};
	r->obj[3].mat[1] = (t_vec){0, 0, 0, 0};
	r->obj[3].mat[2] = (t_vec){0, 0, 0, 0};
	r->obj[3].mat[3] = (t_vec){0, 0, 0, 0};
	r->obj[4].type = SPHERE;
	r->obj[4].mat[0] = (t_vec){20, 20, 0, 0};
	r->obj[4].mat[1] = (t_vec){0, 0, 0, 0};
	r->obj[4].mat[2] = (t_vec){0, 0, 0, 0};
	r->obj[4].mat[3] = (t_vec){0, 0, 0, 0};
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
