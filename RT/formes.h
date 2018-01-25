/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 07:11:59 by esuits            #+#    #+#             */
/*   Updated: 2018/01/25 13:34:19 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMES_H
# define FORMES_H

#include "rtv1.h"
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

t_plan			init_plan(t_vect nrml, double dst, t_col col);
t_sph			init_sph(t_vect ctr, double r, t_col col);

double			intersec_plan(t_ray ray, t_plan plan);
t_col			intersec_sphere(t_ray ray, t_sph sph);
#endif
