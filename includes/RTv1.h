/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 11:11:36 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/10 09:41:59 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>

# define MAX_RAY_DEPTH 5

typedef double		d_mat;

typedef struct		s_vec
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vec;
typedef struct		s_ray
{
	t_vec			ori;
	t_vec			dir;
	double			len;
}					t_ray;
typedef	enum		s_type
{
					NONE = 0,
					CAMERA = 1,
					EYE = 2,
					SPHERE = 3,
					PLANE = 4,
					CONE = 5,
					LIGHT_SPOT = 6,
					LIGHT_DIR = 7,
					LIGHT_CONE = 8,
					LIGHT_POINT = 9
}					t_type;
/*
**	Mat[0] = Local_pos;
**	Mat[1] = World_pos;
**	Mat[2] = Scale;
**	Mat[3] = Size;
*/
typedef struct		s_obj
{
	t_vec			mat[4];
	t_type			type;
	float			radius;
	float			radius2;
	float			width;
	float			height;
	t_vec			surface_col;
	t_vec			emmision_col;
	float			trans;
	float			reflec;
}					t_obj;
typedef struct		s_raytrace
{
	void			*mlx;
	void			*win;
	void			**img;
	void			**data;
	int				w;
	int				h;
	int				bpp;
	int				sl;
	int				endn;
	t_obj			*obj;
}					t_raytrace;

void				put_pixel(double pos[2], int n, t_raytrace *rt, int col);
void    			new_image(t_raytrace *r, int n, int deltax, int deltay);
void   				debug_text(t_raytrace *r);
void				info(t_raytrace *r);
void				trace(t_raytrace *r);
void				back(t_raytrace *r);

double				vec_len(t_vec len);
double				dot(t_vec a, t_vec b);

t_vec				normalise(t_vec v);
t_vec				mult_vec(t_vec v, double a);
t_vec				mult_vec_vec(t_vec a, t_vec b);
t_vec				add_vec(t_vec v, double a);
t_vec				add_vec_vec(t_vec a, t_vec b);
t_vec				vec_swap(t_vec a, t_vec b);
t_vec				minus_vec_vec(t_vec a, t_vec b);
t_vec				minus_vec(t_vec v, double a);
t_vec				vec_flip(t_vec v);

#endif
