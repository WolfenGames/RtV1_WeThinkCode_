/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:23:17 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/15 18:14:17 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		get_type(const char *s)
{
	char	*p;

	p = ft_strmap(s, ft_tolower);
	if (ft_strnequ(p, "eye", 3))
		return (EYE);
	if (ft_strnequ(p, "sphere", 6))
		return (SPHERE);
	if (ft_strnequ(p, "plane", 5))
		return (PLANE);
	if (ft_strnequ(p, "cylinder", 8))
		return (CYLINDER);
	if (ft_strnequ(p, "cone", 4))
		return (CONE);
	if (ft_strnequ(p, "light_spot", 11))
		return (LIGHT_SPOT);
	if (ft_strnequ(p, "light_dir", 10))
		return (LIGHT_DIR);
	if (ft_strnequ(p, "light_cone", 11))
		return (LIGHT_CONE);
	if (ft_strnequ(p, "light_point", 12))
		return (LIGHT_POINT);
	return (NONE);
}

void	setprop(t_obj *obj, char *line)
{
	if (ft_strnequ(line, "Type", 4))
		obj->type = get_type(ft_strchr(line, ' ') + 1);
	if (ft_strnequ(line, "Fov", 3))
		obj->fov = ft_atof(ft_strchr(line, ' ') + 1);
	if (ft_strnequ(line, "Origin", 7))
		vec_assign(obj->ori, ft_strchr(line, ' ') + 1);
	if (ft_strnequ(line, "Rotation", 9))
		vec_assign(obj->rot, ft_strchr(line, ' ') + 1);
	if (ft_strnequ(line, "Size", 4))
		vec_assign(obj->size, ft_strchr(line, ' ') + 1);
	if (ft_strnequ(line, "Radius", 6))
	{
		obj->radius = ft_atof(ft_strchr(line, ' ') + 1);
		obj->radius2 = obj->radius * obj->radius;
	}
	if (ft_strnequ(line, "Color", 5))
		obj->surface_col = get_col(ft_strchr(line, ' ') + 1);
}

void    load_file(int fd, t_raytrace *r)
{
	char	*line;
	t_obj	*obj;

	obj = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '>')
			obj = find_obj(line + 1, r);
		if (line[0] == '-' && obj)
			setprop(obj, line + 1);
	}
	printf("%d\n", r->objsize);
	for (int i = 0; i < r->objsize; i++)
	{
		printf("O::%s\n", r->obj[i].name);
		printf("T::%d\n", r->obj[i].type);
	}
}