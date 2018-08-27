/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 06:49:52 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/27 07:30:32 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	bzero_sphere(t_obj *o)
{
	o->radius = 1;
	o->radius2 = 2;
	o->org[0] = 0;
	o->org[1] = 0;
	o->org[2] = 0;
	o->rot[0] = 0;
	o->rot[1] = 0;
	o->rot[2] = 0;
	o->surface_col = 000000;
}

void	bzero_cone(t_obj *o)
{
	o->radius = 1;
	o->radius2 = 2;
	o->org[0] = 0;
	o->org[1] = 0;
	o->org[2] = 0;
	o->rot[0] = 0;
	o->rot[1] = 0;
	o->rot[2] = 0;
	o->size[0] = 2;
	o->surface_col = 000000;
}

void	bzero_cylinder(t_obj *o)
{
	o->radius = 1;
	o->radius2 = 2;
	o->org[0] = 0;
	o->org[1] = 0;
	o->org[2] = 0;
	o->rot[0] = 0;
	o->rot[1] = 0;
	o->rot[2] = 0;
	o->size[0] = 2;
	o->surface_col = 000000;
}

void	bzero_plane(t_obj *o)
{
	o->org[0] = 0;
	o->org[1] = 0;
	o->org[2] = 0;
	o->rot[0] = 0;
	o->rot[1] = 0;
	o->rot[2] = 0;
	o->surface_col = 000000;
}

void	valid_objects(t_obj *obj)
{
	if (obj->type == SPHERE)
		bzero_sphere(obj);
	if (obj->type == CYLINDER)
		bzero_cylinder(obj);
	if (obj->type == CONE)
		bzero_cone(obj);
	if (obj->type == PLANE)
		bzero_plane(obj);
}