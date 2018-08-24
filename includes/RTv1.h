/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 11:11:36 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/24 12:05:05 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/includes/libft.h"
# include "../matvec/includes/matvec.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>

# define MAX_RAY_DEPTH	5
# define CAM			r->obj[0]
# define CAMFOV			r->obj[0].fov
# define LSO			r->obj[1].org
# define LI				r->obj[1].intensity

typedef double		t_vec[3];
typedef double		t_matrix[4][4];
typedef enum		e_img
{
	SIDE_BAR = 0,
	SCREEN = 1,
	LOGO = 2
}					t_img;
typedef enum		e_v
{
	org = 0,
	ROT = 1,
	SIZE = 2,
	FOV = 3,
	COL = 4,
	RADIUS = 5
}					t_v;
typedef enum		e_ray_type
{
	INCEDENT = 1,
	SHADOW = 2
}					t_ray_type;
typedef struct		s_ray
{
	t_vec			org;
	t_vec			dir;
	double			len;
}					t_ray;
typedef	enum		e_type
{
	NONE = 0,
	CAMERA = 1,
	EYE = 2,
	SPHERE = 3,
	PLANE = 4,
	CONE = 5,
	CYLINDER = 6,
	LIGHT = 7
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
	t_vec			point;
	double			intensity;
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
void				new_image(t_raytrace *r, int n, int deltax, int deltay);
void				debug_text(t_raytrace *r);
void				info(t_raytrace *r);
void				trace(t_raytrace *r);
void				back(t_raytrace *r);

void				load_file(int fd, t_raytrace *r);
void				vec_assign(t_obj *o, t_v v, char *s);
t_obj				*find_obj(char *name, t_raytrace *r);
int					scale_colour(int col1, double r);

void				calccam(t_obj *cam);
void				obj_thingies(t_obj *o);

int					inter_sphere(t_ray *ray, t_obj *obj, double *n);
int					inter_plane(t_ray *ray, t_obj *obj, double *n);
int					inter_cone(t_ray *ray, t_obj *obj, double *near);
int					inter_cylinder(t_ray *ray, t_obj *obj, double *near);
void				apply(t_raytrace *r);
int					get_col(char *line);
int					colour_grad(int col1, int col2, float r);
char				*get_obj_name(t_type i);
char				ft_char_tolower(char c);
char				ft_char_toupper(char c);

#endif
