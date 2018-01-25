/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 03:32:32 by esuits            #+#    #+#             */
/*   Updated: 2018/01/25 19:24:19 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

t_ray	init_ray(t_vect org, t_vect dir)
{
	t_ray ray;

	ray.org = org;
	ray.dir = dir;
	ray.dist = 0;
	return (ray);
}

t_vect	vect_sub(t_vect u, t_vect v)
{
	u.x -= v.x;
	u.y -= v.y;
	u.z -= v.z;
	return (u);
}

double	norme_vect(t_vect u)
{
	return (sqrt(u.x * u.x + u.y * u.y + u.z * u.z));
}

t_vect	normal_vect(t_vect u)
{
	double n;

	n = norme_vect(u);
	if (n <= 0)
		return (init_vect(0, 0, 0));
	u.x = u.x / n;
	u.y = u.y / n;
	u.z = u.z / n;
	return (u);
}

double	vect_mult_scale(t_vect u, t_vect v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_col	send_ray(t_ray *ray, t_env *env)
{
	(void)env;
	return (intersec_sphere(*ray, init_sph(init_vect(0.1, 0.2, 0), 0.2,
					init_col(1,0.7,0,0))));
}
