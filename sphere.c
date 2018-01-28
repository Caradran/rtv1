/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 18:23:58 by esuits            #+#    #+#             */
/*   Updated: 2018/01/28 12:08:58 by esuits           ###   ########.fr       */
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
	b = 2 * vect_mult_scale(ray.dir, oc);
	c = vect_mult_scale(oc, oc) - (sph.r * sph.r);
	delta = b * b - 4 * a * c;
	if (delta <= 0)
		return (-1);
	else
		return ((-b - sqrt(delta)) / (2 * a));
}

double	phong(t_ray ray, t_sph sph, t_vect norm, t_lights *lights)
{
	double	refl;
	t_vect	phongdir;
	t_vect	lgtdir;
	double	phongterm;
	t_lgt	lgt;

	lgt = lights->lgt;
	lgtdir = normal_vect(vect_sub(lgt.vect,
				vect_add(ray.org, vect_scale(ray.dist, ray.dir))));
	refl = 2 * vect_mult_scale(lgtdir, norm);
	phongdir = vect_sub(lgtdir, vect_scale(refl, norm));
	phongterm = vect_mult_scale(phongdir, ray.dir);
	if (phongterm < 0)
		phongterm = 0;
	phongterm = (sph.col.s * pow(phongterm, 50) * lgt.col.s);
	return (phongterm);
}

t_col	intersec_sphere(t_ray ray, t_sph sph, t_env env)
{
	t_vect	norm;
	t_col	fond;
	double	lambert;
	t_col	col;

	fond = init_col(0, 0, 0, 0);
	ray.dist = hit_sphere(ray, sph);
	if (ray.dist >= 0)
	{
		norm = normal_vect(
			vect_sub(vect_add(ray.org,
						vect_scale(ray.dist, ray.dir)), sph.ctr));
		lambert = vect_mult_scale(normal_vect(vect_sub(env.lights->lgt.vect,
				vect_add(ray.org, vect_scale(ray.dist, ray.dir)))), norm);
		col = interpolcol(init_col(0,0,0,0), sph.col, (-vect_mult_scale(norm, ray.dir)));
		col = interpolcol(interpolcol(fond, multcol(col, env.lights->lgt.col), lambert), col, 0.5);
		col = interpolcol(col, addcol(env.lights->lgt.col, col),
				phong(ray, sph, norm, env.lights));
		return (col);
	}
	return (fond);
}
