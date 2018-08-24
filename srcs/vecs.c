/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 07:38:09 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/24 09:11:38 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "string.h"

void    vec_assign(t_obj *o, t_v v, char *s)
{
    char    **sp;
    int     i;

    sp = ft_strsplit(s, ',');
    i = 0;
     while (i < 3 && sp[i])
    {
        if (v == org)
            o->org[i] = ft_atod(sp[i]);
        if (v == ROT)
            o->rot[i] = (double)ft_atod(sp[i]);
        if (v == SIZE)
            o->size[i] = (double)ft_atod(sp[i]);
        free(sp[i]);
        i++;
    }
    if (sp[i])
        free(sp[i]);
    free(sp);
}