/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 18:23:58 by esuits            #+#    #+#             */
/*   Updated: 2018/02/13 18:34:38 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>
#include <stdio.h>

t_sph	init_sph(t_vect ctr, double r, t_col col)
{
	t_sph sph;

	sph.ctr = ctr;
	sph.r = r;
	sph.col = col;
	return (sph);
}

double	hit_sphere(t_ray ray, t_sph sph)
{
	t_vect oc;
	double a;
	double b;
	double c;
	double delta;

	oc = vect_sub(ray.org, sph.ctr);
	a = vect_mult_scale(ray.dir, ray.dir);
	b = 2.0 * vect_mult_scale(ray.dir, oc);
	c = vect_mult_scale(oc, oc) - (sph.r * sph.r);
	delta = b * b - 4.0 * a * c;
	if (delta <= 0.0)
		return (-1.0);
	return ((-b - sqrt(delta)) / (2.0 * a));
}

t_col	intersec_sphere(t_ray ray, t_sph sph, t_env env)
{
	t_vect	norm;

	if (hit_sphere(ray, sph) >= 0.0)
	{
		norm = normal_vect(
			vect_sub(vect_add(ray.org,
						vect_scale(ray.dist, ray.dir)), sph.ctr));
		return (diffuse(env, norm, ray, sph.col));
	}
	return (BACK_COLOR);
}
