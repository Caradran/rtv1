/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:48:18 by esuits            #+#    #+#             */
/*   Updated: 2018/02/15 16:52:50 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cone	init_cone(t_vect org, t_vect dir, double theta, t_col col)
{
	t_cone cone;

	cone.org = org;
	cone.dir = normal_vect(dir);
	cone.theta = theta;
	cone.col = col;
	return (cone);
}

double	hit_cone2(t_ray ray, t_cone cone)
{
	double a;
	double b;
	double k;
	double delta;
	t_vect oc;

	cone.dir = vect_scale(-1.0, cone.dir);
	k = tan(cone.theta);
	k = k * k;
	oc = vect_sub(ray.org, cone.org);
	a = vect_mult_scale(ray.dir, ray.dir)
		- (1 + k) * vect_mult_scale(ray.dir, cone.dir)
		* vect_mult_scale(ray.dir, cone.dir);
	b = 2 * (vect_mult_scale(ray.dir, oc) - (1 + k) *
			vect_mult_scale(ray.dir, cone.dir) * vect_mult_scale(oc, cone.dir));
	k = vect_mult_scale(oc, oc)
		- (1 + k) * vect_mult_scale(oc, cone.dir)
		* vect_mult_scale(oc, cone.dir);
	delta = b * b - 4 * a * k;
	if (delta <= 0.0)
		return (-1.0);
	return ((-b - sqrt(delta)) / (2.0 * a));
}

double	hit_cone(t_ray ray, t_cone cone)
{
	double a;
	double b;
	double k;
	double delta;
	t_vect oc;

	k = tan(cone.theta / 2);
	k = k * k;
	oc = vect_sub(ray.org, cone.org);
	a = vect_mult_scale(ray.dir, ray.dir)
		- (1 + k) * vect_mult_scale(ray.dir, cone.dir) *
		vect_mult_scale(ray.dir, cone.dir);
	b = 2 * (vect_mult_scale(ray.dir, oc) - (1 + k) *
			vect_mult_scale(ray.dir, cone.dir) *
			vect_mult_scale(oc, cone.dir));
	k = vect_mult_scale(oc, oc) - (1 + k) *
		vect_mult_scale(oc, cone.dir) * vect_mult_scale(oc, cone.dir);
	delta = b * b - 4 * a * k;
	if (delta <= 0.0)
		return (-1.0);
	return ((-b - sqrt(delta)) / (2.0 * a));
}

t_vect	normal_cone(t_ray ray, t_cone cone)
{
	double m;
	t_vect p;
	t_vect oc;
	double k;
	t_vect norm;

	p = vect_add(ray.org, vect_scale(ray.dist, ray.dir));
	oc = vect_sub(ray.org, cone.org);
	m = vect_mult_scale(ray.dir, vect_scale(ray.dist, cone.dir)) +
		vect_mult_scale(oc, cone.dir);
	k = tan(cone.theta);
	norm = normal_vect(vect_sub(vect_sub(p, cone.org),
				vect_scale(1.0 + k * k * m, cone.dir)));
	if (m > 0.0)
		return (norm);
	cone.dir = vect_scale(-1.0, cone.dir);
	p = vect_add(ray.org, vect_scale(ray.dist, ray.dir));
	m = vect_mult_scale(ray.dir, vect_scale(ray.dist, cone.dir)) +
		vect_mult_scale(oc, cone.dir);
	norm = normal_vect(vect_sub(vect_sub(p, cone.org),
				vect_scale(1.0 + k * k * m, cone.dir)));
	return (norm);
}

t_col	intersec_cone(t_ray ray, t_formes *obj, t_env env)
{
	if (hit_cone(ray, obj->cone) >= 0.0)
	{
		obj->norm = normal_cone(ray, obj->cone);
		return (diffuse(env, obj, ray, obj->cone.col));
	}
	return (BACK_COLOR);
}
