/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 20:55:14 by esuits            #+#    #+#             */
/*   Updated: 2018/02/22 22:07:39 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	print_obj(t_formes *formes)
{
	while (formes)
	{
		if (formes->type == 1)
			printf("Sphere :\n -center :\n  -x : %12f\n  -y : %12f\n  -z : %12f\n -color :\n  -r : %12f\n  -g : %12f\n  -b : %12f\n  -s : %12f\n -radius : %f\n\n", 
				formes->sph.ctr.x, formes->sph.ctr.y, formes->sph.ctr.z,
				formes->sph.col.r, formes->sph.col.g, formes->sph.col.b, formes->sph.col.s,
				formes->sph.r);
		if (formes->type == 2)
			printf("Plane :\n -normal :\n  -x : %12f\n  -y : %12f\n  -z : %12f\n -color :\n  -r : %12f\n  -g : %12f\n  -b : %12f\n  -s : %12f\n -dist : %10f\n\n",
				formes->plan.nrml.x, formes->plan.nrml.y, formes->plan.nrml.z,
				formes->plan.col.r, formes->plan.col.g, formes->plan.col.b, formes->plan.col.s,
				formes->plan.dst);
		if (formes->type == 3)
			printf("cone :\n -position :\n  -x : %12f\n  -y : %12f\n  -z :%12f\n -direction :\n  -x : %12f\n  -y : %12f\n  -z :%12f\n-color :\n  -r : %12f\n  -g : %12f\n  -b : %12f\n  -s : %12f\n -theta : %10f\n\n",
				formes->cone.org.x, formes->cone.org.y, formes->cone.org.z,
				formes->cone.dir.x, formes->cone.dir.y, formes->cone.dir.z,
				formes->cone.col.r, formes->cone.col.g, formes->cone.col.b, formes->cone.col.s,
				formes->cone.theta);
		if (formes->type == 4)
			printf("cylindre :\n -position :\n  -x : %12f\n  -y : %12f\n  -z :%12f\n direction :\n  -x : %12f\n  -y : %12f\n  -z :%12f\n -color :\n  -r : %12f\n  -g : %12f\n  -b : %12f\n  -s : %12f\n -radius : %10f\n\n",
				formes->cyl.pos.x, formes->cyl.pos.y, formes->cyl.pos.z,
				formes->cyl.dir.x, formes->cyl.dir.y, formes->cyl.dir.z,
				formes->cyl.col.r, formes->cyl.col.g, formes->cyl.col.b, formes->cyl.col.s,
				formes->cyl.r);
		formes = formes->next;
	}
}
