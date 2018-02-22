/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 03:32:32 by esuits            #+#    #+#             */
/*   Updated: 2018/02/22 20:41:06 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

t_ray	init_ray(t_vect org, t_vect dir)
{
	t_ray ray;

	ray.org = org;
	ray.dir = normal_vect(dir);
	ray.dist = -1.0;
	return (ray);
}

t_col	send_ray(t_ray ray, t_env *env)
{
	t_formes	*ptr;
	double		dist;
	int			i;
	t_formes	*nearest;

	i = 0;
	ptr = env->formes;
	nearest = NULL;
	while (ptr)
	{
		if (((ptr->type != 0) &&
					(dist = hit_shape()[ptr->type - 1](ray, ptr)) >= 0)
				&& ((ray.dist > dist || ray.dist == -1) && dist >= 0))
		{
			nearest = ptr;
			ray.dist = dist;
		}
		ptr = ptr->next;
		i++;
	}
	if (!nearest)
		return (BACK_COLOR);
	if (nearest->type != 0)
		return (intersection()[nearest->type - 1](ray, nearest, *env));
	return (BACK_COLOR);
}
