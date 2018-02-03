/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 20:55:14 by esuits            #+#    #+#             */
/*   Updated: 2018/02/03 21:20:09 by esuits           ###   ########.fr       */
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
		formes = formes->next;
	}
}
