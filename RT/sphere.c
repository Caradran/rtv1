/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 18:23:58 by esuits            #+#    #+#             */
/*   Updated: 2018/01/25 19:21:56 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

t_sph		init_sph(t_vect ctr, double r, t_col col)
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
	b = 2 * vect_mult_scale(oc, ray.dir);
	c = vect_mult_scale(oc, oc) - (sph.r * sph.r);
	delta = b*b - 4*a*c;
	if (delta <= 0)
		return (-1);
	else
		return (-b - sqrt(delta) / (2 * a));
}

t_col	intersec_sphere(t_ray ray, t_sph sph)
{
	double	dist;
	t_vect	norm;
	t_col	fond;

	fond = init_col(0, 0, 0, 0);
	dist = hit_sphere(ray, sph) / 2;
	if (dist >= 0)
	{
		printf("dist = %f\n", dist);
		norm = normal_vect(
				vect_sub(vect_add(vect_scale(dist, ray.dir), ray.org),
				sph.ctr));
		printf("%f %f %f\n", norm.x, norm.y, norm.z);
		printf("%f\n", norme_vect(vect_dot(norm, ray.dir)));
		return (interpolcol(fond, sph.col, norme_vect(vect_dot(norm, ray.dir))));
	}
	return (fond);
}
