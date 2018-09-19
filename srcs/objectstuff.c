/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objectstuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:01:49 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/27 07:29:17 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj	*new_obj(char *name, t_raytrace *r)
{
	t_obj	*new_objs;

	r->objsize += 1;
	new_objs = (t_obj*)ft_memalloc(sizeof(t_obj) * r->objsize);
	ft_memmove(new_objs, r->obj, sizeof(t_obj) * (r->objsize - 1));
	free(r->obj);
	r->obj = new_objs;
	r->obj[r->objsize - 1].name = ft_strdup(name);
	valid_objects(&r->obj[r->objsize - 1]);
	return (&r->obj[r->objsize - 1]);
}

t_obj	*find_obj(char *name, t_raytrace *r)
{
	int		i;

	i = 0;
	while (i < r->objsize)
	{
		if (ft_strequ(name, r->obj[i].name))
			return (&r->obj[i]);
		i++;
	}
	return (new_obj(name, r));
}

void	calccam(t_obj *cam)
{
	t_matrix	a;
	t_vec		b;

	ft_bzero(cam->otw, sizeof(double) * 16);
	ft_bzero(a, sizeof(double) * 16);
	fill_mat_rot_x(cam->otw, cam->rot[0] * M_PI / 180.0);
	fill_mat_rot_y(a, cam->rot[1] * M_PI / 180.0);
	mult_mat(cam->otw, a, cam->otw);
	b[0] = 0;
	b[1] = 0;
	b[2] = -1;
	mult_vec(cam->otw, b, b);
	fill_rot_v(a, b, (cam->rot[2] * M_PI) / 180.0);
	mult_mat(cam->otw, a, cam->otw);
}

void	obj_thingies(t_obj *o)
{
	double	a[4][4];

	ft_bzero(o->otw, sizeof(double) * 16);
	ft_bzero(a, sizeof(double) * 16);
	fill_mat_rot_y(o->otw, o->rot[0] * M_PI / 180.0);
	fill_mat_rot_x(a, o->rot[1] * M_PI / 180.0);
	mult_mat(o->otw, a, o->otw);
	fill_mat_rot_z(a, (o->rot[2] * M_PI) / 180.0);
	mult_mat(o->otw, a, o->otw);
	fill_mat_trans(a, o->org);
	mult_mat(o->otw, a, o->otw);
	inver(o->otw, o->wto);
}

void	apply(t_raytrace *r)
{
	int		x;

	x = 0;
	calccam(&CAM);
	while (x < r->objsize)
	{
		obj_thingies(&r->obj[x]);
		x++;
	}
}
