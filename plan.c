/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 21:12:47 by esuits            #+#    #+#             */
/*   Updated: 2018/01/28 05:03:40 by esuits           ###   ########.fr       */
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
					vect_scale(-plan.dst, plan.nrml)));
		return (-b / a);
	}
}

t_col	intersec_plan(t_ray ray, t_plan plan)
{
	double	dist;
	t_vect	norm;
	t_col	fond;

	fond = init_col(0, 0, 0, 0);
	dist = hit_plan(ray, plan);
	if (dist >= 0)
	{
		norm = plan.nrml;
		return (interpolcol(fond, plan.col, (1.5 - dist) / 1.5));
	}
	return (fond);
}
