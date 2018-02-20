/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:29:07 by esuits            #+#    #+#             */
/*   Updated: 2018/02/20 06:10:09 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cyl	init_cyl(t_vect pos, t_vect dir, double r, t_col col){
	return ((t_cyl){pos, dir, r, col});
}

double	hit_cyl(t_ray ray, t_cyl cyl)
{
	double a;
	double b;
	double c;
	double delta;
	t_vect oc;

	oc = vect_sub(ray.org, cyl.org);
	a = vect_mult_scale(ray.dir, ray.dir) - (vect_mult_scale(ray.dir, cyl.dir)
			* vect_mult_scale(ray.dir, cyl.dir));
	b = 2.0 * (vect_mult_scale(ray.dir, oc) - (vect_mult_scale(ray.dir, cyl.dir)
			* vect_mult_scale(oc, cyl.dir)));
	c = vect_mult_scale(oc, oc) - vect_mult_scale(vect_scale(cyl.r, oc)
			, vect_scale(cyl.r, oc)) - cyl.r * cyl.r;
	delta = b * b - 4.0 * a * c;
	if (delta <= 0.0)
		return (-1.0);
	return ((-b - sqrt(delta)) / (2.0 * a));
}

t_vect	normal_cyl(t_ray ray, t_cyl cyl)
{
	t_vect hit;
	t_vect oc;
	double k;
	t_vect norm;

	hit = vect_add(ray.org, vect_scale(ray.dist, ray.dir));
	oc = vect_sub(ray.org, cyl.org);
	if (vect_mult_scale(cyl.dir, vect_sub(hit, oc)) < 0)
		cyl.dir = vect_scale(-1.0, cyl.dir);
	norm = normal_vect(vect_sub(vect_add(hit, oc), vect_sub(cyl.org, hit)));
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
