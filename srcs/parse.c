/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:23:17 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/15 17:44:41 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"


void    load_file(int fd, t_raytrace *r)
{
	char	*line;
	t_obj	*obj;

	obj = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '>')
		{
			obj = find_obj(line + 1, r);
		}
	}
	printf("%d\n", r->objsize);
	for (int i = 0; i < r->objsize; i++)
	{
		printf("O::%s\n", r->obj[i].name);
	}
}