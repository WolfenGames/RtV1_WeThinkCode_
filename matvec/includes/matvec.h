/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matvec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@42.FR>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 07:06:13 by jwolf             #+#    #+#             */
/*   Updated: 2018/08/24 09:52:47 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATVEC_H
# define MATVEC_H

#include "../../includes/rtv1.h"

typedef double		t_vec[3];
typedef double		t_matrix[4][4];

void				fill_mat_rot_x(double mat[4][4], double ang);
void				fill_mat_rot_y(double mat[4][4], double ang);
void				fill_mat_rot_z(double mat[4][4], double ang);
void				fill_rot_v(double a[4][4], t_vec b, double ang);
void	            fill_mat_trans(t_matrix m, t_vec trans);
void				normalise(t_vec v);
void				calco(double a[4][4], double b[4][4], double size,
							int t[2]);
void				inver(t_matrix src, t_matrix ret);
void				cofactor(double a[4][4], double size);
void				mult_mat(double a[4][4], double b[4][4], double r[4][4]);

double				*mult_vec_f(t_vec v, double a, t_vec r);
double				*mult_vec_vec(t_vec a, t_vec b, t_vec r);
double				*add_vec_vec(t_vec a, t_vec b, t_vec r);
double				*add_vec(t_vec v, double a, t_vec r);
double				*minus_vec(t_vec v, double a, t_vec r);
double				*minus_vec_vec(t_vec a, t_vec b, t_vec r);
void				vec_dup(t_vec a, t_vec b);
void				vec_swap(t_vec a, t_vec b);
double				*vec_flip(t_vec v, t_vec r);
double				maxd(double a, double b);

void				m4_dup(t_matrix src, t_matrix ret);
double				vec_len(t_vec v);
double				dot(t_vec a, t_vec b);
double				determinant(double a[4][4], double size);
double				maxd(double a, double b);
double				mind(double a, double b);
double				*mult_vec(double a[4][4], double v[3], double r[3]);
double				*mult_trans(double a[4][4], double v[3], double r[3]);
double				angle_find(t_vec a, t_vec b);
int					quad(t_vec co, double t[2]);


#endif