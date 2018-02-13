/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:34:43 by esuits            #+#    #+#             */
/*   Updated: 2018/02/13 18:30:37 by esuits           ###   ########.fr       */
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
	phongterm = (col.s * pow(phongterm, 50.0) * lgt.col.s);
	return (phongterm);
}

double lambert(t_ray ray, t_vect norm, t_lights *lights)
{
	return(vect_mult_scale(normal_vect(vect_sub(lights->lgt.vect,
		vect_add(ray.org, vect_scale(ray.dist, ray.dir)))), norm));
}

t_col	diffuse(t_env env, t_vect norm, t_ray ray, t_col col_obj)
{
	double		lmbrt;
	t_col		col;
	t_col		fond;
	t_col		spec;

	col = BACK_COLOR;
	fond = col;
	spec = col;
	while (env.lights)
	{
		if (hit_obj(env.lights->lgt, ray, env.formes))
		{
			col = addcol(fond, col);
			env.lights = env.lights->next;
			continue ;
		}
		lmbrt = lambert(ray, norm, env.lights);
		if (lmbrt < 0.0)
			lmbrt = 0;
		col = addcol(interpolcol(fond, multcol(col_obj,
					env.lights->lgt.col), lmbrt * lmbrt), col);
		spec = addcol(spec, interpolcol(fond, env.lights->lgt.col,
					phong(ray, col_obj, norm, env.lights) / 3.0));
		env.lights = env.lights->next;
	}
	return (addcol(spec, col));
}
