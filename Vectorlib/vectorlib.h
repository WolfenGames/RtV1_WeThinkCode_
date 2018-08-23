/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 17:34:57 by ibotha            #+#    #+#             */
/*   Updated: 2018/08/12 13:28:10 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# define FILLVEC(V, X, Y, Z) (V[0] = X, V[1] = Y, V[2] = Z)
# include <math.h>
# include "libft.h"

typedef double t_matrix[4][4];
typedef double t_vec[4];

void	put_vector(t_vec vec, const char *name);
void	put_matrix(t_matrix m, const char *name);
double	dot(t_vec a, t_vec b);
double	*v_cross(t_vec a, t_vec b, t_vec ret);
double	length(t_vec v);
void	normalize(t_vec v);
void	vec_from_str(t_vec ret, char *str);
double	*v_multi(t_vec a, double b, t_vec ret);
double	*v_sub(t_vec a, t_vec b, t_vec ret);
double	*v_add(t_vec a, t_vec b, t_vec ret);
double	*v_mult(t_vec a, t_vec b, t_vec ret);
double	*v_div(t_vec a, t_vec b, t_vec ret);
void	fill_m_rot_v(double a, t_vec axis, t_matrix m);
double	*transformvec(const t_matrix m, t_vec v, t_vec ret);
double	*transformw(const t_matrix m, t_vec v, t_vec ret);
double	*transform(const t_matrix m, t_vec v, t_vec ret);
void	m3_mult(const t_matrix a, const t_matrix b, t_matrix ret);
void	m4_mult(const t_matrix a, const t_matrix b, t_matrix ret);
void	fill_m_rot_z(t_matrix m, double th);
void	fill_m_rot_x(t_matrix m, double th);
void	fill_m_rot_y(t_matrix m, double th);
double	find_angle(t_vec a, t_vec b);
void	vec_dup(t_vec src, t_vec dest);
double	v_sum(t_vec	vec);
void	v_rot_e(t_vec rot, t_vec vec, t_vec ret);
void	fill_m_transform(t_matrix m, t_vec trans);
void	m4_invert(t_matrix src, t_matrix ret);
double	determinant(t_matrix a, double size);
void	cofactor(t_matrix a, double size);
void	transpose(t_matrix a, t_matrix fac, double size);
void	m4_dup(t_matrix src, t_matrix ret);
double	*reflect(t_vec inc, t_vec norm, t_vec ret);

#endif
