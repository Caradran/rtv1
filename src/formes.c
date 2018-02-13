/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 02:21:45 by esuits            #+#    #+#             */
/*   Updated: 2018/02/13 13:30:14 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_formes		*init_formes(t_env *env)
{
	t_formes	*formes;

	(void)env;
	if (!(formes = malloc(sizeof(t_formes))))
		return (NULL);
	formes->type = 3;
	formes->cone = init_cone(init_vect(2, 0, 0),
			init_vect(-0.2, -1, 1), M_PI/5.0,  init_col(1, 1, 1, 1));
	if (!(formes->next = malloc(sizeof(t_formes))))
		return (NULL);
	formes->next->type = 3;
	formes->next->cone = init_cone(init_vect(10, 0, 0),
			init_vect(-1, 1, 1), M_PI/10.0,  init_col(1, 1, 1, 1));
	if (!(formes->next->next = malloc(sizeof(t_formes))))
		return (NULL);
	formes->next->next->type = 1;
	formes->next->next->sph = init_sph(init_vect(10, 0, 0), 0.2, init_col(1,1,1,1));
	if (!(formes->next->next->next = malloc(sizeof(t_formes))))
		return (NULL);
	formes->next->next->next->type = 1;
	formes->next->next->next->sph = init_sph(init_vect(0.2,0.5,0), 0.1, init_col(1,1,1,1));
	if (!(formes->next->next->next->next = malloc(sizeof(t_formes))))
		return (NULL);
	formes->next->next->next->next->type = 2;
	formes->next->next->next->next->plan = init_plan(init_vect(0.5, 0, 0), 10, init_col(1, 1, 1, 1));
	formes->next->next->next->next = NULL;
//	print_obj(formes);
	return (formes);
}

t_lights		*init_lights(t_env *env)
{
	t_lights	*lights;
	double		n = 10;

	(void)env;
	if (!(lights = malloc(sizeof(t_lights))))
		return (NULL);
	lights->lgt = init_lgt(init_col(0, 1, 0.5, 1), init_vect(0, n * -1, 0));
//	lights->next = NULL;
	if (!(lights->next = malloc(sizeof(t_lights))))
		return (NULL);
	lights->next->lgt = init_lgt(init_col(1, 0, 0.5, 1), init_vect(0, n*0.5, n*0.866));
//	lights->next->next = NULL;
	if (!(lights->next->next = malloc(sizeof(t_lights))))
		return (NULL);
	lights->next->next->lgt = init_lgt(init_col(0.5, 0, 1, 1),
			init_vect(0, n * 0.5, n * -0.866));
	lights->next->next->next = NULL;
	return (lights);
}

int				hit_obj(t_lgt lgt, t_ray camray, t_formes *formes)
{
	double		dist;
	t_vect		dir;
	t_ray		ray;
	t_formes	*ptr;


	dir = vect_sub(vect_add(camray.org, vect_scale(camray.dist, camray.dir)), 
	lgt.vect);
	ray = init_ray(lgt.vect, normal_vect(dir));
	ptr = formes;
	while (ptr)
	{
		if (((ptr->type == 1) && (dist = hit_sphere(ray, ptr->sph)) >= 0) &&
		((ray.dist > dist || ray.dist == -1) && dist >= 0))
				ray.dist = dist;
		else if (((ptr->type == 2) && (dist = hit_plan(ray, ptr->plan)) >= 0)
				&& ((ray.dist > dist || ray.dist == -1) && dist >= 0
					&& dist < R_THRESHOLD))
			ray.dist = dist;
		else if (((ptr->type == 3) && (dist = hit_cone(ray, ptr->cone)) >= 0) &&
		((ray.dist > dist || ray.dist == -1) && dist >= 0))
				ray.dist = dist;
		ptr = ptr->next;
	}
	if (ray.dist > (norme_vect(dir) - 0.000000001))
		return (0);
	return (1);
}
