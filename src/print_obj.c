/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 20:55:14 by esuits            #+#    #+#             */
/*   Updated: 2018/02/23 09:32:02 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	print_obj(t_formes *formes)
{
	while (formes)
	{
		if (formes->type == 1)
			printf("Sphere :\n -center :\n  -x : %12f\n  -y : %12f\n  -z : %12f\n -color :\n  -r : %12f\n  -g : %12f\n  -b : %12f\n  -s : %12f\n -radius : %8f\n\n", 
				formes->sph.ctr.x, formes->sph.ctr.y, formes->sph.ctr.z,
				formes->sph.col.r, formes->sph.col.g, formes->sph.col.b, formes->sph.col.s,
				formes->sph.r);
		if (formes->type == 2)
			printf("Plane :\n -normal :\n  -x : %12f\n  -y : %12f\n  -z : %12f\n -color :\n  -r : %12f\n  -g : %12f\n  -b : %12f\n  -s : %12f\n -dist : %10f\n\n",
				formes->plan.nrml.x, formes->plan.nrml.y, formes->plan.nrml.z,
				formes->plan.col.r, formes->plan.col.g, formes->plan.col.b, formes->plan.col.s,
				formes->plan.dst);
		if (formes->type == 3)
			printf("Cone :\n -position :\n  -x : %12f\n  -y : %12f\n  -z : %12f\n -direction :\n  -x : %12f\n  -y : %12f\n  -z : %12f\n-color :\n  -r : %12f\n  -g : %12f\n  -b : %12f\n  -s : %12f\n -theta : %9f\n\n",
				formes->cone.org.x, formes->cone.org.y, formes->cone.org.z,
				formes->cone.dir.x, formes->cone.dir.y, formes->cone.dir.z,
				formes->cone.col.r, formes->cone.col.g, formes->cone.col.b, formes->cone.col.s,
				formes->cone.theta);
		if (formes->type == 4)
			printf("Cylindre :\n -position :\n  -x : %12f\n  -y : %12f\n  -z : %12f\n direction :\n  -x : %12f\n  -y : %12f\n  -z : %12f\n -color : \n  -r : %12f\n  -g : %12f\n  -b : %12f\n  -s : %12f\n -radius : %8f\n\n",
				formes->cyl.pos.x, formes->cyl.pos.y, formes->cyl.pos.z,
				formes->cyl.dir.x, formes->cyl.dir.y, formes->cyl.dir.z,
				formes->cyl.col.r, formes->cyl.col.g, formes->cyl.col.b, formes->cyl.col.s,
				formes->cyl.r);
		formes = formes->next;
	}
}

void		print_cam(t_cam cam)
{
	printf("Camera :\n -postion:\n  -x : %12f\n  -y : %12f\n  -z : %12f\n front :\n  -x : %12f\n  -y : %12f\n  -z : %12f\n right :\n  -x : %12f\n  -y : %12f\n  -z : %12f\n down :\n  -x : %12f\n  -y : %12f\n  -z : %12f\n\n"
			, cam.org.x, cam.org.y, cam.org.z
			, cam.frt.x, cam.frt.y, cam.frt.z
			, cam.rgt.x, cam.rgt.y, cam.rgt.z
			, cam.dwn.x, cam.dwn.y, cam.dwn.z);
}

void		print_lights(t_lights *lights)
{
	while (lights)
	{
		printf("Light :\n -postion:\n  -x : %12f\n  -y : %12f\n  -z : %12f\n -color :\n  -r : %12f\n  -g : %12f\n  -b : %12f\n  -s : %12f\n\n"
				, lights->lgt.vect.x, lights->lgt.vect.y, lights->lgt.vect.z
				, lights->lgt.col.r, lights->lgt.col.g, lights->lgt.col.b, lights->lgt.col.s);
		lights = lights->next;
	}
}
