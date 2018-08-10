/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:16:29 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/10 10:13:39 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void    new_image(t_raytrace *r, int n, int deltax, int deltay)
{
	r->img[n] = mlx_new_image(r->mlx, r->w + deltax, r->h + deltay);
	r->data[n] = mlx_get_data_addr(r->img[n], &r->bpp, &r->sl, &r->endn);
	r->bpp /= 8;
}

void    put_pixel(double pos[], int n, t_raytrace *r, int col)
{
	int     x;
	int     y;

	x = pos[0];
	y = pos[1];
	if (x >= 0 && y >= 0 && x < r->w && y < r->h)
	{
		*(unsigned int *)(r->data[n] + ((int)x
			* r->bpp) + ((int)y * r->sl)) = col;
	}
}

char    *get_obj_name(t_type i)
{
	if (i == EYE)
		return ("Eye");
	if (i == CAMERA)
		return ("Camera");
	if (i == SPHERE)
		return ("Sphere");
	if (i == LIGHT_SPOT)
		return ("Light Spot");
	if (i == LIGHT_DIR)
		return ("Light Directional");
	if (i == LIGHT_CONE)
		return ("Light Cone");
	if (i == LIGHT_POINT)
		return ("Light Point");
	if (i == PLANE)
		return ("Plane");
	if (i == CONE)
		return ("Cone");
	return ("Not Defined");
}

void    debug_text(t_raytrace *r)
{
	int     x;
	int     y;

	x = 0;
	y = 0;
	while (x < 5)
	{
		mlx_string_put(r->mlx, r->win, 10, 20 * x, 0X3BAB98,
						get_obj_name(r->obj[x].type));
		x++;
	}
}