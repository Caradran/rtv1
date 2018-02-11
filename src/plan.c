/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 21:12:47 by esuits            #+#    #+#             */
/*   Updated: 2018/02/10 09:22:15 by esuits           ###   ########.fr       */
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

t_col	intersec_plan(t_ray ray, t_plan plan, t_env env)
{
	t_vect	norm;
	double	labrt;
	t_col	fond;
	t_col	col;
	t_col	spec;

	fond = BACK_COLOR;
	spec = BACK_COLOR;
	if ((hit_plan(ray, plan)) >= 0.0)
	{
		norm = plan.nrml;
		col = fond;
		while (env.lights)
		{
			if (hit_obj(env.lights->lgt, ray, env.formes))
			{
				col = addcol(fond, col);
				env.lights = env.lights->next;
				continue ;
			}
			labrt = lambert(ray, norm, env.lights);
			if (labrt >= 0)
				labrt = 0.0;
//			printf("%f\n", ray.dist);
			col = addcol(interpolcol(fond, multcol(plan.col,
							env.lights->lgt.col), labrt * labrt), col);
			spec = addcol(spec, interpolcol(fond, env.lights->lgt.col,
						phong(ray, plan.col, norm, env.lights)/3.0));
			env.lights = env.lights->next;
		}
		col = addcol(spec, col);
		return (col);
	}
	return (fond);
}
