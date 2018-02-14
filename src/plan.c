/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 21:12:47 by esuits            #+#    #+#             */
/*   Updated: 2018/02/14 19:49:53 by esuits           ###   ########.fr       */
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

double	hit_plan(t_ray ray, t_plan plan)
{
	double a;
	double b;

	a = vect_mult_scale(ray.dir, plan.nrml);
	if (a == 0)
		return (-1);
	else
	{
		b = vect_mult_scale(plan.nrml, vect_add(ray.org,
					vect_scale(plan.dst, plan.nrml)));
		return (-b / a);
	}
}

t_col	intersec_plan(t_ray ray, t_formes *pln, t_env env)
{
	if (ray.dist >= 0.0)
	{
		pln->norm = pln->plan.nrml;
		return (diffuse(env, pln, ray, pln->plan.col));
	}
	return (BACK_COLOR);
}
