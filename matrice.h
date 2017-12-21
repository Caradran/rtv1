/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 00:13:04 by esuits            #+#    #+#             */
/*   Updated: 2017/12/21 07:11:51 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICE_H
# define MATRICE_H

# include "rtv1.h"

typedef struct	s_mat
{
	int		i;
	int		j;
	double	**mat;
}				t_mat;

typedef struct	s_vect
{
	double x;
	double y;
	double z;
}				t_vect;

typedef struct	s_ray
{
	t_vect org;
	t_vect dir;
}				t_ray;

typedef struct	s_cam
{
	t_vect org;
	t_vect frt;
	t_vect rgt;
	t_vect dwn;
}				t_cam;

typedef struct	s_col
{
	double r;
	double g;
	double b;
	double s;
}				t_col;

typedef struct	s_lgt
{
	t_vect	vect;
	t_col	col;
}				t_lgt;

void			add_mat(t_mat *a, t_mat *b);
void			sub_mat(t_mat *a, t_mat *b);
t_mat			*mult_mat(t_mat a, t_mat b);
void			scale_mat(double a, t_mat *b);

t_mat			rot_mat(t_vect *v, double theta);
t_mat			id_mat(void);

t_vect			normal_vect(t_vect u);
double			norme_vect(t_vect u);
void			vect_mat_mult(t_mat a, t_vect *u);
t_vect			vect_mult(t_vect u, t_vect v);
t_vect			vect_scale(double a, t_vect u);
t_vect			vect_add(t_vect u, t_vect v);
double			norme_vect(t_vect u);
t_vect			normal_vect(t_vect u);

t_cam			init_cam(t_vect org, t_vect look_at);
t_ray			init_ray(t_vect org, t_vect dir);
t_vect			init_vect(double x, double y, double z);
t_col			init_col(double r, double g, double b, double s);
t_lgt			init_lgt(t_col col, t_vect vect);
int				init_env(t_env *env);
int				init_mat(t_mat *mat, int i, int j);
#endif
