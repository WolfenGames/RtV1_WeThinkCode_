/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planeicals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 09:23:24 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/24 10:11:29 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void plane_norm(t_ray *ray, t_obj *obj, double n)
{
	t_ray	r;

	ft_memmove(&r, ray, sizeof(t_ray));
	mult_vec_f(r.dir, n, r.dir);
	add_vec_vec(r.dir, r.org, obj->point);
	obj->norm[0] = 0;
    obj->norm[1] = 0;
    obj->norm[2] = obj->point > 0 ? -1 : 1;
    mult_trans(obj->otw, obj->point, obj->point);
    mult_vec(obj->otw, obj->norm, obj->norm);
	normalise(obj->norm);
}

int     inter_plane(t_ray *r, t_obj *obj, double *n)
{
	t_ray   tempray;
    double  t;

    mult_vec(obj->wto, r->dir, tempray.dir);
    mult_trans(obj->wto, r->org, tempray.org);
    if (!((tempray.org[2] < 0 && tempray.dir[2] > 0)
        || (tempray.org[2] > 0 && tempray.dir[2] < 0)))
        return (0);
    normalise(tempray.dir);
    t = ABS(tempray.org[2] / tempray.dir[2]) - 0.0001;
    if (*n < t)
        return (0);
    *n = t;
    plane_norm(&tempray, obj, *n);
    return (1);
}
