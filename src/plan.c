/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 21:12:47 by esuits            #+#    #+#             */
/*   Updated: 2018/02/01 18:06:20 by esuits           ###   ########.fr       */
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

static double lambert(t_ray ray, t_vect norm, t_env env)
{
	return(vect_mult_scale(normal_vect(vect_sub(env.lights->lgt.vect,
				vect_add(ray.org, vect_scale(ray.dist, ray.dir)))), norm));
}

t_col	intersec_plan(t_ray ray, t_plan plan, t_env env)
{
	t_vect	norm;
	double	labrt;
	t_col	fond;
	t_col	col;

	fond = BACK_COLOR;
	if ((hit_plan(ray, plan)) >= 0.0)
	{
		norm = plan.nrml;
//		printf("%lf %lf %lf\n", norm.x, norm.y, norm.z);
//		printf("%f\n", lambert(ray, norm, env));
		labrt = -lambert(ray, norm, env);
		if (labrt < 0)
			return (fond);
//		printf("%lf\n", labrt);
		col = fond;
		col = interpolcol(interpolcol(fond, multcol(plan.col, env.lights->lgt.col),
					labrt), multcol(col, env.lights->lgt.col), 0.5);
		/*col = interpolcol(col, addcol(env.lights->lgt.col, col),*/
				/*phong(ray, plan.col, norm, env.lights));*/
		return (col);
	}
	return (fond);
}
