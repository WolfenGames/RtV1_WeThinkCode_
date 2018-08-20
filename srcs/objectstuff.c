/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objectstuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:01:49 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/17 12:51:30 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_obj	*new_obj(char *name, t_raytrace *r)
{
	t_obj	*new_objs;

	r->objsize += 1;
	new_objs = (t_obj*)ft_memalloc(sizeof(t_obj) * r->objsize);
	ft_memmove(new_objs, r->obj, sizeof(t_obj) * (r->objsize - 1));
	free(r->obj);
	r->obj = new_objs;
	r->obj[r->objsize - 1].name = ft_strdup(name);
	return (&r->obj[r->objsize - 1]);
}

t_obj   *find_obj(char *name, t_raytrace *r)
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