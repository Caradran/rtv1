/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 21:12:47 by esuits            #+#    #+#             */
/*   Updated: 2018/02/25 05:47:06 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_plan	init_plan(t_vect nrml, double dst, t_col col)
{
	t_plan plan;

	plan.nrml = normal_vect(nrml);
	plan.dst = dst;
	plan.col = col;
	return (plan);
}

double	hit_plan(t_ray ray, t_formes *formes)
{
	double a;
	double b;

	a = vect_mult_scale(ray.dir, formes->plan.nrml);
	if (a == 0)
		return (-1);
	b = vect_mult_scale(formes->plan.nrml, vect_add(ray.org,
				vect_scale(formes->plan.dst, formes->plan.nrml)));
	return (-b / a);
}

t_col	intersec_plan(t_ray ray, t_formes *pln, t_env env)
{
	if (ray.dist >= 0.0)
	{
		pln->norm = pln->plan.nrml;
        if (vect_mult_scale(pln->norm, ray.dir) > 0)
            pln->norm = vect_scale(-1, pln->norm);
		return (diffuse(env, pln, ray, pln->plan.col));
	}
	return (BACK_COLOR);
}
