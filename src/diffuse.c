/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:34:43 by esuits            #+#    #+#             */
/*   Updated: 2018/02/22 21:05:27 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
	phongterm = (col.s * pow(phongterm, 100.0) * lgt.col.s);
	return (phongterm);
}

double	lambert(t_ray ray, t_vect norm, t_lights *lights)
{
	double lmbrt;

	lmbrt = vect_mult_scale(normal_vect(vect_sub(lights->lgt.vect,
		vect_add(ray.org, vect_scale(ray.dist, ray.dir)))), norm);
	if (lmbrt < 0)
		return (0);
	return (lmbrt);
}

t_col	diffuse(t_env env, t_formes *forme, t_ray ray, t_col col_obj)
{
	double		lmbrt;
	t_col		col;
	t_col		spec;
	double		dist;

	col = BACK_COLOR;
	spec = col;
	while (env.lights)
	{
		if ((dist = (hit_obj(env.lights->lgt, ray, env.formes, forme))) < 0)
		{
			env.lights = env.lights->next;
			continue ;
		}
		lmbrt = lambert(ray, forme->norm, env.lights);
		col = addcol(interpolcol(BACK_COLOR,
				mult_scale_col(env.expo / (dist * dist), multcol(col_obj,
				env.lights->lgt.col)), lmbrt * lmbrt), col);
		spec = addcol(spec, mult_scale_col(env.expo / (dist * dist),
					interpolcol(BACK_COLOR, env.lights->lgt.col,
						phong(ray, col_obj, forme->norm, env.lights))));
		env.lights = env.lights->next;
	}
	return (addcol(spec, col));
}
