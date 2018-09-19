/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:23:17 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/27 10:19:53 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_type(const char *s)
{
	char	*p;
	t_type	ret;

	ret = NONE;
	p = ft_strmap(s, ft_char_tolower);
	if (ft_strnequ(p, "eye", 3))
		ret = EYE;
	if (ft_strnequ(p, "sphere", 6))
		ret = SPHERE;
	if (ft_strnequ(p, "plane", 5))
		ret = PLANE;
	if (ft_strnequ(p, "cylinder", 8))
		ret = CYLINDER;
	if (ft_strnequ(p, "cone", 4))
		ret = CONE;
	if (ft_strnequ(p, "light", 11))
		ret = LIGHT;
	free(p);
	return (ret);
}

void	setprop(t_obj *obj, char *line)
{
	char	*s;

	s = ft_strmap(line, ft_char_tolower);
	if (ft_strnequ(s, "type ", 5))
		obj->type = get_type(ft_strchr(line, ' ') + 1);
	if (ft_strnequ(s, "fov ", 4))
		obj->fov = ft_atod(ft_strchr(line, ' ') + 1);
	if (ft_strnequ(s, "origin ", 7))
		vec_assign(obj, org, ft_strchr(line, ' ') + 1);
	if (ft_strnequ(s, "rotation ", 9))
		vec_assign(obj, ROT, ft_strchr(line, ' ') + 1);
	if (ft_strnequ(s, "size ", 5))
		vec_assign(obj, SIZE, ft_strchr(line, ' ') + 1);
	if (ft_strnequ(s, "radius ", 7))
	{
		obj->radius = ft_atod(ft_strchr(line, ' ') + 1);
		obj->radius2 = obj->radius * obj->radius;
	}
	if (ft_strnequ(s, "color ", 6))
		obj->surface_col = get_col(ft_strchr(line, ' ') + 1);
	if (ft_strnequ(s, "intensity ", 9))
		obj->intensity = ft_atod(ft_strchr(line, ' ') + 1);
	free(s);
}

void	load_file(int fd, t_raytrace *r)
{
	char	*line;
	char	*tmp;
	t_obj	*obj;

	obj = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		tmp = line;
		if (line[0] == '>')
			obj = find_obj(line + 1, r);
		if (line[0] == '-' && obj)
			setprop(obj, line + 1);
		free(line);
	}
	if (line && obj)
		free(line);
	apply(r);
}
