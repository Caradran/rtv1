/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 02:21:45 by esuits            #+#    #+#             */
/*   Updated: 2018/02/25 01:31:36 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "parser.h"

double			hit_obj(t_lgt lgt, t_ray camray, t_formes *formes,
		t_formes *objet)
{
	double		dist;
	t_vect		dir;
	t_ray		ray;
	t_formes	*ptr;
	t_formes	*ombre;

	dir = vect_sub(vect_add(camray.org, vect_scale(camray.dist, camray.dir)),
	lgt.vect);
	ray = init_ray(lgt.vect, normal_vect(dir));
	ptr = formes;
	ombre = NULL;
	while (ptr)
	{
		if (((ptr->type != 0) &&
			(dist = hit_shape()[ptr->type - 1](ray, ptr)) >= 0) &&
			((ray.dist > dist || ray.dist == -1) && dist >= 0))
		{
			ray.dist = dist;
			ombre = ptr;
		}
		ptr = ptr->next;
	}
	if (ombre && ombre == objet)
		return (ray.dist);
	return (-1);
}
