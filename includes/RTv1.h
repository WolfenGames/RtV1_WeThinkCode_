/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 11:11:36 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/23 08:23:37 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/includes/libft.h"
# include "../Vectorlib/vectorlib.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>

# define MAX_RAY_DEPTH	5
# define CAM 			r->obj[0]

typedef double		d_mat;

//typedef double		t_vec[3];
typedef double		t_matrix[4][4];
typedef enum		s_img
{
					SIDE_BAR = 0,
					SCREEN = 1,
					LOGO = 2
}					t_img;
typedef enum		s_v
{
					org = 0,
					ROT = 1,
					SIZE = 2,
					FOV = 3,
					COL = 4,
					RADIUS = 5
}					t_v;
typedef struct		s_ray
{
	t_vec			org;
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
					CYLINDER = 6,
					LIGHT_SPOT = 7,
					LIGHT_DIR = 8,
					LIGHT_CONE = 9,
					LIGHT_POINT = 10
}					t_type;
typedef struct		s_obj
{
	char			*name;
	double			wto[4][4];
	double			otw[4][4];
	t_vec			rot;
	t_vec			org;
	t_vec			norm;
	t_vec			size;
	t_type			type;
	double			radius;
	double			radius2;
	double			fov;
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
	int				objsize;
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
void				load_file(int fd, t_raytrace *r);
void    			vec_assign(t_obj *o, t_v v, char *s);
t_obj  				*find_obj(char *name, t_raytrace *r);

double				vec_len(t_vec v);
double				dot(t_vec a, t_vec b);
double				determinate(double a[4][4], double size);
double				maxd(double a, double b);
double  			*mult_vec(double a[4][4], double v[3], double r[3]);
double  			*mult_trans(double a[4][4], double v[3], double r[3]);
double				angle_find(t_vec a, t_vec b);

double				*mult_vec_f(t_vec v, double a, t_vec r);
double				*mult_vec_vec(t_vec a, t_vec b, t_vec r);
double				*add_vec_vec(t_vec a, t_vec b, t_vec r);
double				*add_vec(t_vec v, double a, t_vec r);
double				*minus_vec(t_vec v, double a, t_vec r);
double				*minus_vec_vec(t_vec a, t_vec b, t_vec r);
void				vec_dup(t_vec a, t_vec b);
void				vec_swap(t_vec a, t_vec b);
void				obj_thingies(t_obj *o);
double				*vec_flip(t_vec v, t_vec r);
double				maxd(double a, double b);

int					get_col(char *line);
int					colour_grad(int col1, int col2, float r);
char    			*get_obj_name(t_type i);
char				ft_char_tolower(char c);
char				ft_char_toupper(char c);
int					inter_cylinder(t_ray *ray, t_obj *obj, double *n);
int					inter_cone(t_ray ray, t_obj obj, double *near);
int					inter_sphere(t_ray ray, t_obj obj, double *n);
t_bool				quad(double a, double b, double c, double d[2]);

#endif
