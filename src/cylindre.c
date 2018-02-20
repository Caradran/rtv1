/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:29:07 by esuits            #+#    #+#             */
/*   Updated: 2018/02/20 12:57:22 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cyl	init_cyl(t_vect pos, t_vect dir, double r, t_col col){
	return ((t_cyl){pos, dir, r, col});
}

double	hit_cyl(t_ray ray, t_formes *forme)
{
	double a;
	double b;
	double c;
	double delta;
	t_vect tmp;

	tmp = vect_sub(ray.dir, vect_dot(ray.dir, forme->cyl.dir));
	a = vect_mult_scale(tmp, tmp);
	b = 2.0 * vect_mult_scale(tmp, vect_sub(vect_sub(
					ray.org, vect_dot(ray.org, forme->cyl.dir)), forme->cyl.pos));
	tmp = vect_sub(vect_sub(
					ray.org, vect_dot(ray.org, forme->cyl.dir)), forme->cyl.pos);
	c = vect_mult_scale(tmp, tmp) - forme->cyl.r * forme->cyl.r;
/*	oc = vect_sub(ray.org, forme->cyl.pos);
	a = vect_mult_scale(ray.dir, ray.dir) - (vect_mult_scale(ray.dir, forme->cyl.dir)
			* vect_mult_scale(ray.dir, forme->cyl.dir));
	b = 2.0 * (vect_mult_scale(ray.dir, oc) - (vect_mult_scale(ray.dir,
					forme->cyl.dir)
			* vect_mult_scale(oc, forme->cyl.dir)));
	c = vect_mult_scale(oc, oc) - vect_mult_scale(vect_scale(forme->cyl.r, oc)
			, vect_scale(forme->cyl.r, oc)) - forme->cyl.r * forme->cyl.r;*/
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
	if (vect_mult_scale(cyl.dir, oc) < 0)
		cyl.dir = vect_scale(-1.0, cyl.dir);
	height = norme_vect(vect_dot(cyl.dir, oc));
	norm = normal_vect(vect_sub(oc, vect_scale(height, cyl.dir)));
	return (norm);
}

t_col	intersec_cyl(t_ray ray, t_formes *obj, t_env env)
{
	if (ray.dist >= 0.0)
	{
		obj->norm = normal_cyl(ray, obj->cyl);
//		return (mult_scale_col(vect_mult_scale(obj->norm, ray.dir), init_col(1,1,1,1)));
		return (diffuse(env, obj, ray, obj->cyl.col));
	}
	return (BACK_COLOR);
}
