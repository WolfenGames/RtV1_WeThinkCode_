/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 07:05:00 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/24 08:31:27 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/matvec.h"

void    fill_mat_rot_x(double m[4][4], double th)
{
	t_matrix a;

	ft_bzero(a, sizeof(a));
	m4_dup(a, m);
	m[1][1] = cos(th);
	m[1][2] = sin(th);
	m[2][1] = -m[1][2];
	m[2][2] = m[1][1];
	m[0][0] = 1;
	m[3][3] = 1;
}

void    fill_mat_rot_y(double m[4][4], double th)
{
	t_matrix a;

	ft_bzero(a, sizeof(a));
	m4_dup(a, m);
	m[0][0] = cos(th);
	m[0][2] = sin(th);
	m[2][0] = -m[0][2];
	m[2][2] = m[0][0];
	m[1][1] = 1;
	m[3][3] = 1;
}

void    fill_mat_rot_z(double m[4][4], double th)
{
	t_matrix a;

	ft_bzero(a, sizeof(a));
	m4_dup(a, m);
	m[0][0] = cos(th);
	m[1][0] = sin(th);
	m[0][1] = -m[1][0];
	m[1][1] = m[0][0];
	m[2][2] = 1;
	m[3][3] = 1;
}

void	fill_mat_trans(t_matrix m, t_vec trans)
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][1] = 1;
	m[1][0] = 0;
	m[1][2] = 0;
	m[2][2] = 1;
	m[2][1] = 0;
	m[2][0] = 0;
	m[0][3] = 0;
	m[1][3] = 0;
	m[2][3] = 0;
	m[3][3] = 1;
	m[3][0] = trans[0];
	m[3][1] = trans[1];
	m[3][2] = trans[2];
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