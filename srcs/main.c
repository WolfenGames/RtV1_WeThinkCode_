/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:18:45 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/09 08:23:37 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int     update(t_raytrace *r)
{
    trace(r);
    return (0);
}

int     keys(int key, t_raytrace *r)
{
    if (key == 53)
        but(0, r);
    return (0);
}

int     butt(int b, t_raytrace *r)
{
    (void)b;
    (void)r;
    exit(0);
}

void    set_hooks(t_raytrace *r)
{
    mlx_loop_hook(r->mlx, update, r);
    mlx_hook(r->mlx, 2, 0, keys, r);
    mlx_hook(r->mlx, 17, 0, butt, r);
}

int     main(void)
{
    t_raytrace  *r;

    r = (t_raytrace *)malloc(sizeof(t_raytrace));
    r->w = 800;
    r->h = 800;
    r->mlx = mlx_init();
    r->win = mlx_new_window(r->mlx, r->w, r->h, "RTv1");
    mlx_loop(r->mlx);
}