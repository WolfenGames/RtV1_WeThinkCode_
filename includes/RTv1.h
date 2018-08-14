/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 11:11:36 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/14 18:38:30 by jwolf            ###   ########.fr       */
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

typedef double		t_vec[3];
typedef double		t_matrix[4][4];
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
typedef struct		s_obj
{
	double			wto[4][4];
	double			otw[4][4];
	t_vec			rot;
	t_vec			ori;
	t_vec			norm;
	t_type			type;
	double			radius;
	double			radius2;
	double			width;
	double			height;
	unsigned int	surface_col;
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
	double			objsize;
}					t_raytrace;

void				put_pixel(double pos[2], int n, t_raytrace *rt, int col);
void    			new_image(t_raytrace *r, int n, int deltax, int deltay);
void   				debug_text(t_raytrace *r);
void				info(t_raytrace *r);
void				trace(t_raytrace *r);
void				back(t_raytrace *r);
void				normalise(t_vec v);
void    			fill_mat_rot_x(double mat[4][4], double ang);
void    			fill_mat_rot_y(double mat[4][4], double ang);
void    			fill_mat_rot_z(double mat[4][4], double ang);
void				fill_rot_v(double a[4][4], t_vec b, double ang);
void				calco(double a[4][4], double b[4][4], double size, int t[2]);
void				calccam(t_obj *cam);
void				inver(t_matrix src, t_matrix ret);
void				cofactor(double a[4][4], double size);
void				mult_mat(double a[4][4], double b[4][4], double r[4][4]);

double				vec_len(t_vec v);
double				dot(t_vec a, t_vec b);
double				determinate(double a[4][4], double size);
double				maxd(double a, double b);
double  			*mult_vec(double a[4][4], double v[3], double r[3]);
double  			*mult_trans(double a[4][4], double v[3], double r[3]);
double				angle_find(t_vec a, t_vec b);

#endif
