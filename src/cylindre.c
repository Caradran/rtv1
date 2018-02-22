/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:29:07 by esuits            #+#    #+#             */
/*   Updated: 2018/02/22 20:50:21 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cyl	init_cyl(t_vect pos, t_vect dir, double r, t_col col)
{
	return ((t_cyl){pos, normal_vect(dir), r, col});
}

double	hit_cyl(t_ray ray, t_formes *forme)
{
	double a;
	double b;
	double c;
	double delta;
	t_vect tmp;

	tmp = vect_mult(forme->cyl.dir, ray.dir);
	a = vect_mult_scale(tmp, tmp);
	b = 2.0 * vect_mult_scale(tmp, vect_mult(forme->cyl.dir, vect_sub(ray.org,
					forme->cyl.pos)));
	tmp = vect_mult(forme->cyl.dir, vect_sub(ray.org, forme->cyl.pos));
	c = vect_mult_scale(tmp, tmp) - forme->cyl.r * forme->cyl.r;
	delta = b * b - 4.0 * a * c;
	if (delta <= 0.0)
		return (-1.0);
	return ((-b - sqrt(delta)) / (2.0 * a));
}

t_vect	normal_cyl(t_ray ray, t_cyl cyl)
{
	t_vect hit;
	t_vect oc;
	double height;
	t_vect norm;

	hit = vect_add(ray.org, vect_scale(ray.dist, ray.dir));
	oc = vect_sub(hit, cyl.pos);
	height = vect_mult_scale(cyl.dir, oc);
	norm = normal_vect(vect_sub(oc, vect_scale(height, cyl.dir)));
	return (norm);
}

t_col	intersec_cyl(t_ray ray, t_formes *obj, t_env env)
{
	if (ray.dist >= 0.0)
	{
		obj->norm = normal_cyl(ray, obj->cyl);
		return (diffuse(env, obj, ray, obj->cyl.col));
	}
	return (BACK_COLOR);
}
