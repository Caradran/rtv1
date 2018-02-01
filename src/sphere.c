/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 18:23:58 by esuits            #+#    #+#             */
/*   Updated: 2018/02/01 18:56:39 by esuits           ###   ########.fr       */
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
	else
		return ((-b - sqrt(delta)) / (2.0 * a));
}

double	phong(t_ray ray, t_col col, t_vect norm, t_lights *lights)
{
	double	refl;
	t_vect	phongdir;
	t_vect	lgtdir;
	double	phongterm;
	t_lgt	lgt;

	lgt = lights->lgt;
	lgtdir = normal_vect(vect_sub(lgt.vect,
				vect_add(ray.org, vect_scale(ray.dist, ray.dir))));
	refl = 2.0 * vect_mult_scale(lgtdir, norm);
	phongdir = vect_sub(lgtdir, vect_scale(refl, norm));
	phongterm = vect_mult_scale(phongdir, ray.dir);
	if (phongterm < 0.0)
		phongterm = 0.0;
	phongterm = (col.s * pow(phongterm, 50.0) * lgt.col.s);
	return (phongterm);
}

static double lambert(t_ray ray, t_vect norm, t_env env)
{
	return(vect_mult_scale(normal_vect(vect_sub(env.lights->lgt.vect,
				vect_add(ray.org, vect_scale(ray.dist, ray.dir)))), norm));
}

t_col	intersec_sphere(t_ray ray, t_sph sph, t_env env)
{
	t_vect	norm;
	t_col	fond;
	double	lbrt;
	t_col	col;

	fond = init_col(0,0,0,0);
	ray.dist = hit_sphere(ray, sph);
	if (ray.dist >= 0)
	{
		norm = normal_vect(
			vect_sub(vect_add(ray.org,
						vect_scale(ray.dist, ray.dir)), sph.ctr));
		lbrt = lambert(ray, norm, env);
		col = interpolcol(fond, sph.col, (-vect_mult_scale(norm, ray.dir)));
		col = interpolcol(interpolcol(fond, multcol(col, env.lights->lgt.col),
					lbrt), multcol(col, env.lights->lgt.col), 0.5);
		col = interpolcol(col, interpolcol(env.lights->lgt.col, col, 0.5),
				phong(ray, sph.col, norm, env.lights));
		return (col);
	}
	return (fond);
}
