/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:26:05 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/15 16:13:13 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void    fill_mat_rot_x(double mat[4][4], double ang)
{
	ft_bzero(mat, sizeof(double) * 16);
	mat[0][0] = 1;
	mat[1][1] = cos(ang);
	mat[1][2] = sin(ang);
	mat[2][2] = mat[1][1];
	mat[2][1] = -mat[1][2];
	mat[3][3] = 1;
}

void    fill_mat_rot_y(double mat[4][4], double ang)
{
	ft_bzero(mat, sizeof(double) * 16);
	mat[1][1] = 1;
	mat[0][0] = cos(ang);
	mat[2][0] = sin(ang);
	mat[2][2] = mat[0][0];
	mat[0][2] = -mat[2][0];
	mat[3][3] = 1;
}

void    fill_mat_rot_z(double mat[4][4], double ang)
{
	ft_bzero(mat, sizeof(double) * 16);
	mat[2][2] = 1;
	mat[0][0] = cos(ang);
	mat[1][0] = sin(ang);
	mat[1][1] = mat[0][0];
	mat[0][1] = -mat[1][0];
	mat[3][3] = 1;
}

void	fill_mat_trans(double mat[4][4], t_vec t)
{
	ft_bzero(mat, sizeof(double) * 16);
	mat[0][0] = 1;
	mat[1][1] = 1;
	mat[2][2] = 1;
	mat[3][3] = 1;
	mat[3][0] = t[0];
	mat[3][1] = t[1];
	mat[3][2] = t[2];
}

double  *mult_vec(double a[4][4], double v[3], double r[3])
{
	double  cpy[3];

	cpy[0] = v[0] * a[0][0] + v[1] * a[0][1] + v[2] * a[0][2];
	cpy[1] = v[0] * a[1][0] + v[1] * a[1][1] + v[2] * a[1][2];
	cpy[2] = v[0] * a[2][0] + v[1] * a[2][1] + v[2] * a[2][2];
	ft_memmove(r, cpy, 3 * sizeof(double));
	return(r);
}

double  *mult_trans(double a[4][4], double v[3], double r[3])
{
	double  cpy[3];

	cpy[0] = v[0] * a[0][0] + v[1] * a[0][1] + v[2] * a[0][2] + v[3] + a[3][0];
	cpy[1] = v[0] * a[1][0] + v[1] * a[1][1] + v[2] * a[1][2] + v[3] + a[3][1];
	cpy[2] = v[0] * a[2][0] + v[1] * a[2][1] + v[2] * a[2][2] + v[3] + a[3][2];
	ft_memmove(r, cpy, 3 * sizeof(double));
	return (r);
}

void	mult_mat(double a[4][4], double b[4][4], double r[4][4])
{
	double	cpy[4][4];
	int		x;
	int		y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			cpy[x][y] = a[y][0] * b[0][x] + a[y][1] * b[1][x] + a[y][2] *
						b[2][x] + a[y][3] * b[3][x];
			y++;
		}
		x++;
	}
	ft_memmove(r, cpy, 16 * sizeof(double));
}

double	angle_find(t_vec a, t_vec b)
{
	t_vec	r;
	
	r[0] = dot(a, a);
	r[1] = dot(a, b);
	r[2] = dot(b, b);
	return (acos(r[1]/sqrt(r[0] * r[2])));
}

double	dot(t_vec a, t_vec b)
{
//	printf("DOT-A::%lf		%lf		%lf\nDOT-B::%lf		%lf		%lf\nVALUE::%lf\n",
//			a[0], a[1], a[2], b[0], b[1], b[2],
//			(a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]));
	return ((a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]));
}

void	normalise(t_vec v)
{
	double	nor2;

	nor2 = 1 / sqrt((v[0] * v[0]) + (v[1] * v[1]) + (v[2] * v[2]));
	v[0] *= nor2;
	v[1] *= nor2;
	v[2] *= nor2;
}

double	vec_len(t_vec v)
{
	return (sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]));
}


void	fill_rot_v(double a[4][4], t_vec b, double ang)
{
	double	cosa;
	double	sina;

	cosa = cos(ang);
	sina = sin(ang);
	normalise(b);
	a[0][0] = cosa + (b[0] * b[0]) * (1 - cosa);
	a[1][0] = (b[0] * b[1]) * (1 - cosa) - (b[2] * sina);
	a[2][0] = (b[2] * b[0]) * (1 - cosa) - (b[1] * sina);
	a[0][1] = (b[0] * b[1]) * (1 - cosa) - (b[2] * sina);
	a[1][1] = cosa + (b[1] * b[1]) * (1 - cosa);
	a[2][1] = (b[1] * b[2]) * (1 - cosa) - (b[0] * sina);
	a[0][2] = (b[2] * b[0]) * (1 - cosa) - (b[1] * sina);
	a[1][2] = (b[2] * b[1]) * (1 - cosa) - (b[0] * sina);
	a[2][2] = cosa + (b[2] * b[2]) * (1 - cosa);
	a[3][3] = 1;
}

void	calco(double a[4][4], double b[4][4], double size, int dim[2])
{
	int		i[4];

	i[3] = 0;
	i[2] = 0;
	i[0] = -1;
	while (++i[0] < size)
	{
		i[1] = -1;
		while (++i[1] < size)
		{
			if (i[0] != dim[0] && i[1] != dim[1])
			{
				b[i[3]][i[2]] = a[i[0]][i[1]];
				if (i[2] < (size - 2))
					i[2]++;
				else
				{
					i[2] = 0;
					i[3]++;
				}
			}
		}
	}
}

void	determinate_work(double a[4][4], double b[4][4], double size, int c)
{
	int	i[4];

	i[2] = 0;
	i[3] = 0;
	i[0] = -1;
	while (++i[0] < size)
	{
		i[1] = -1;
		while (++i[1] < size)
		{
			b[i[0]][i[1]] = 0;
			if (i[0] != 0 && i[1] != c)
			{
				b[i[2]][i[3]] = a[i[0]][i[1]];
				if (i[3] < (size - 2))
					i[3]++;
				else
				{
					i[3] = 0;
					i[2]++;
				}
			}
		}
	}
}

double	determinate(double a[4][4], double size)
{
	double	s;
	double	ret;
	double	b[4][4];
	int		c;

	s = 1;
	ret = 0;
	if (size == 1)
		return (a[0][0]);
	c = -1;
	while (++c < size)
	{
		determinate_work(a, b, size, c);
		ret = ret + s * (a[0][c] * determinate(b, size - 1));
		size = -1 * s;
	}
	return (ret);
}

void		m4_dup(t_matrix src, t_matrix ret)
{
	int i;
	int j;

	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
			ret[i][j] = src[i][j];
	}
}

static void	det_work(t_matrix a, t_matrix b, double size, int c)
{
	int	i[4];

	i[2] = 0;
	i[3] = 0;
	i[0] = -1;
	while (++i[0] < size)
	{
		i[1] = -1;
		while (++i[1] < size)
		{
			b[i[0]][i[1]] = 0;
			if (i[0] != 0 && i[1] != c)
			{
				b[i[2]][i[3]] = a[i[0]][i[1]];
				if (i[3] < (size - 2))
					i[3]++;
				else
				{
					i[3] = 0;
					i[2]++;
				}
			}
		}
	}
}

double		determinant(t_matrix a, double size)
{
	double		s;
	double		ret;
	t_matrix	b;
	int			c;

	s = 1;
	ret = 0;
	if (size == 1)
		return (a[0][0]);
	c = -1;
	while (++c < size)
	{
		det_work(a, b, size, c);
		ret = ret + s * (a[0][c] * determinant(b, size - 1));
		s = -1 * s;
	}
	return (ret);
}

void	transpose(double a[4][4], double fac[4][4], double size)
{
	int		i;
	int		j;
	double	d;

	i = -1;
	d = determinant(a, size);
	if (d != 0)
		while (++i < size)
		{
			j = -1;
			while (++j < size)
			{
				a[i][j] = fac[j][i] / d;
			}
		}
}

void	cofactor(double a[4][4], double size)
{
	t_matrix	b;
	t_matrix	fac;
	int			dim[2];

	dim[0] = -1;
	while (++dim[0] < size)
	{
		dim[1] = -1;
		while (++dim[1] < size)
		{
			calco(a, b, size, dim);
			fac[dim[0]][dim[1]] = pow(-1, dim[0] + dim[1])
				* determinant(b, size - 1);
		}
	}
	transpose(a, fac, size);
}

void	inver(t_matrix src, t_matrix ret)
{
	t_matrix	a;

	m4_dup(src, a);
	cofactor(a, 4);
	m4_dup(a, ret);
}

void	calccam(t_obj *cam)
{
	double	a[4][4];
	t_vec	b;

	ft_bzero(cam->otw, sizeof(double) * 16);
	ft_bzero(a, sizeof(double) * 16);
	fill_mat_rot_x(cam->otw, cam->rot[1] * M_PI / 180.0);
	fill_mat_rot_y(a, cam->rot[0] * M_PI / 180.0);
	mult_mat(cam->otw, a, cam->otw);
	b[0] = 0;
	b[1] = 0;
	b[2] = -1;
	mult_vec(cam->otw, b, b);
	fill_rot_v(a, b, (cam->rot[2] * M_PI) / 180.0);
	mult_mat(cam->otw, a, cam->otw);
}

double	*mult_vec_f(t_vec v, double a, t_vec r)
{
	r[0] = v[0] * a;
	r[1] = v[1] * a;
	r[2] = v[2] * a;
	return (r);
}

double	*mult_vec_vec(t_vec a, t_vec b, t_vec r)
{
	r[0] = a[0] * b[0];
	r[1] = a[1] * b[1];
	r[2] = a[2] * b[2];
	return (r);
}

double	*add_vec_vec(t_vec a, t_vec b, t_vec r)
{
	r[0] = a[0] + b[0];
	r[1] = a[1] + b[1];
	r[2] = a[2] + b[2];
	return (r);
}

double	*add_vec(t_vec v, double a, t_vec r)
{
	r[0] = v[0] + a;
	r[1] = v[1] + a;
	r[2] = v[2] + a;
	return (r);
}

double	*minus_vec(t_vec v, double a, t_vec r)
{
	r[0] = v[0] - a;
	r[1] = v[1] - a;
	r[2] = v[2] - a;
	return (r);
}

double	*minus_vec_vec(t_vec a, t_vec b, t_vec r)
{
	r[0] = a[0] - b[0];
	r[1] = a[1] - b[1];
	r[2] = a[2] - b[2];
	return (r);
}

void	vec_dup(t_vec a, t_vec b)
{
	b[0] = a[0];
	b[1] = a[1];
	b[2] = a[2];
}

void	vec_swap(t_vec a, t_vec b)
{
	t_vec	t;

	vec_dup(a, t);
	vec_dup(b, a);
	vec_dup(t, b);
}

double	*vec_flip(t_vec v, t_vec r)
{
	mult_vec_f(v, -1, r);
	return (r);
}

double	maxd(double a, double b)
{
	if (a < b)
		return (b);
	else
		return (a);
}