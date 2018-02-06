/
************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:48:18 by esuits            #+#    #+#             */
/*   Updated: 2018/02/05 15:59:08 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cone	init_cone(t_vect org, t_vect dir, double theta, t_col col)
{
	t_cone cone;

	cone.org = org;
	cone.dir = dir;
	cone.theta = theta;
	cone.col = col;
	return (cone);
}

double	hit_cone(t_ray ray, t_cone cone)
{
	double a;
	double b;
	double c;
	double delta;
	t_vect oc;

	oc = vect_sub(ray.org, cone.org);
	a = vect_mult_scale(ray.dir, ray.dir) 
		- (cos(theta) + 1) * vect_mult_scale(ray.dir, cone.dir);
	b = 2 * (vect_mult_scale(ray.dir, oc) - (cos(theta) + 1) *
			vect_mult_scale(ray.dir, cone.dir) * vect_mult_scale(oc, cone.dir));
	c = vect_mult_scale(oc, oc) 
		- (cos(theta) + 1) * vect_mult_scale(oc, cone.dir);
	delta = b * b - 4 * a * c;
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

	p = vect_add(ray.org, vect_scale(ray.dist, ray.dir));
	oc = vect_sub(ray.org, cone.org);
	m = vect_mult_scale(ray.dir, vect_scale(ray.dist,cone.dir)) +
		vect_mult_scale(oc, cone.dir);
	k = tan(cone.theta);
	return(normal_vect(vect_sub(vect_sub(p, cone.org),
				vect_scale( 1 + k * k * m, cone.dir))));
}

t_col	intersec_cone(t_ray ray, t_cone cone, t_env env)
{
	t_vect	norm;
	t_col	fond;
	t_col	col;
	t_col	spec;
	double	lmbrt;

	fond = init_col(0.0, 0.0, 0.0, 0.0);
	spec = fond;
	ray.dist = hit_cone(ray, sph);
	if (ray.dist >= 0.0)
	{
		norm = normal_cone(ray, cone);
		col = fond;
		while (env.lights)
		{
			lmbrt = lambert(ray, norm, env.lights);
			if (lmbrt < 0.0)
				lmbrt = 0.0;
			col = addcol(interpolcol(fond, multcol(sph.col,
							env.lights->lgt.col), lmbrt), col);
			spec = addcol(spec, interpolcol(fond,
						env.lights->lgt.col,
				phong(ray, sph.col, norm, env.lights) / 3.0));
			env.lights = env.lights->next;
		}
		col = interpolcol(fond, col, (-vect_mult_scale(norm, ray.dir)));
		col = addcol(spec, col);
		return (col);
	}
	return (fond);
}