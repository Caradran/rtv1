/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 00:13:04 by esuits            #+#    #+#             */
/*   Updated: 2018/02/03 21:08:03 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICE_H
# define MATRICE_H

# include <SDL.h>
# include "formes.h"

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
	t_vect	org;
	t_vect	dir;
	double	dist;
	int		forme;
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

typedef struct	s_sph
{
	t_vect	ctr;
	t_col	col;
	double	r;
}				t_sph;

typedef struct	s_plan
{
	t_vect	nrml;
	double	dst;
	t_col	col;
}				t_plan;

typedef struct	s_cyl
{
	t_vect	nrml;
	double	dst;
	t_col	col;
}				t_cyl;

typedef struct	s_formes
{
	struct s_formes		*next;
	int					type;
	t_sph				sph;
	t_plan				plan;
}				t_formes;

typedef struct	s_lights
{
	t_lgt			lgt;
	struct s_lights	*next;
	double			nblgt;
}				t_lights;

typedef struct	s_env
{
	t_cam		cam;
	void		*mlx;
	SDL_Window	*win;
	double		i;
	SDL_Surface	*surface;
	t_formes	*formes;
	t_lights	*lights;
	uint32_t	rpp;
}				t_env;

void			print_objs(t_formes *formes);


void			add_mat(t_mat *a, t_mat *b);
void			sub_mat(t_mat *a, t_mat *b);
t_mat			*mult_mat(t_mat a, t_mat b);
void			scale_mat(double a, t_mat *b);

t_mat			rot_mat(t_vect v, double theta);
t_mat			id_mat(void);

t_vect			normal_vect(t_vect u);
double			norme_vect(t_vect u);
void			vect_mat_mult(t_mat a, t_vect *u);
t_vect			vect_mult(t_vect u, t_vect v);
t_vect			vect_dot(t_vect u, t_vect v);
t_vect			vect_scale(double a, t_vect u);
double			vect_mult_scale(t_vect u, t_vect v);
t_vect			vect_add(t_vect u, t_vect v);
t_vect			vect_sub(t_vect u, t_vect v);
double			norme_vect(t_vect u);
t_vect			normal_vect(t_vect u);
t_vect			rot_vect(t_vect v, double theta, t_vect axis);

t_cam			init_cam(t_vect org, t_vect look_at);
t_ray			init_ray(t_vect org, t_vect dir);
t_vect			init_vect(double x, double y, double z);
t_col			init_col(double r, double g, double b, double s);
t_lgt			init_lgt(t_col col, t_vect vect);
int				init_env(t_env *env);
int				init_mat(t_mat *mat, int i, int j);

t_col			send_ray(t_ray *ray, t_env *env);
int				coltoi(t_col col);
t_col			interpolcol(t_col col1, t_col col2, double t);
t_col			addcol(t_col col1, t_col col2);
t_col			multcol(t_col col1, t_col col2);

t_formes		*init_formes(t_env *env);
t_lights		*init_lights(t_env *env);
t_plan			init_plan(t_vect nrml, double dst, t_col col);
t_sph			init_sph(t_vect ctr, double r, t_col col);

t_col			intersec_plan(t_ray ray, t_plan plan, t_env env);
t_col			intersec_sphere(t_ray ray, t_sph sph, t_env env);

double			phong(t_ray ray, t_col col, t_vect norm, t_lights *lights);
double			hit_sphere(t_ray ray, t_sph sph);
double			hit_plan(t_ray ray, t_plan plan);
#endif
