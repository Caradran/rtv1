/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 02:21:45 by esuits            #+#    #+#             */
/*   Updated: 2018/02/23 08:26:00 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "parser.h"

t_formes		*init_formes(t_env *env)
{
	/*t_formes	*formes;*/

	/*(void)env;*/
	/*if (!(formes = malloc(sizeof(t_formes))))*/
		/*return (NULL);*/
	/*formes->type = 2;*/
	/*formes->plan = init_plan(init_vect(-1, 0, 0), 2, init_col(0.2, 0.6, 0.5, 1));*/
	/*if (!(formes->next = malloc(sizeof(t_formes))))*/
		/*return (NULL);*/
	/*formes->next->type = 3;*/
	/*formes->next->cone = init_cone(init_vect(1, 0, 0),*/
			/*init_vect(0, 1, 1), M_PI / 3,  init_col(1, 0, 1, 1));*/
	/*if (!(formes->next->next = malloc(sizeof(t_formes))))*/
		/*return (NULL);*/
	/*formes->next->next->type = 1;*/
	/*formes->next->next->sph = init_sph(init_vect(1, 0.3, 0.3), 0.3, init_col(0,1,1,0));*/
	/*if (!(formes->next->next->next = malloc(sizeof(t_formes))))*/
		/*return (NULL);*/
	/*formes->next->next->next->type = 4;*/
	/*formes->next->next->next->cyl = init_cyl(init_vect(1, 0, 0),*/
			/*init_vect(0.5,1,0), 0.2, init_col(1,0.5,1,0));*/
	/*if (!(formes->next->next->next->next = malloc(sizeof(t_formes))))*/
		/*return (NULL);*/
	/*formes->next->next->next->next->type = 4;*/
	/*formes->next->next->next->next->cyl =*/
		/*init_cyl(init_vect(1, 0, 0),*/
				/*init_vect(0,0,1), 0.2, init_col(1, 1, 0.5, 1));*/
	/*formes->next->next->next->next->next = NULL;*/
	if ((parse_file("scenes/test1.bgnouf", env)) != PARSER_VALID)
		ft_putstr(HD"Parser exited with error syntax\n"C_NRM);
	print_obj(env->formes);
	return (env->formes);
}

t_lights		*init_lights(t_env *env)
{
	t_lights	*lights;
	double		n = 5;

	(void)env;
	if (!(lights = malloc(sizeof(t_lights))))
		return (NULL);
	lights->lgt = init_lgt(init_col(1, 0, 0, 1),
			init_vect(-10, n * -1, 0));
//	lights->next = NULL;
	if (!(lights->next = malloc(sizeof(t_lights))))
		return (NULL);
	lights->next->lgt = init_lgt(init_col(0, 0, 1, 1),
			init_vect(-10, n * 0.5, n * 0.866));
//	lights->next->next = NULL;
	if (!(lights->next->next = malloc(sizeof(t_lights))))
		return (NULL);
	lights->next->next->lgt = init_lgt(init_col(0, 1, 0, 1),
			init_vect(-10, n * 0.5, n * -0.866));
	lights->next->next->next = NULL;
	return (NULL);
}

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
	if (ombre && !ft_memcmp(ombre, objet, sizeof(t_formes)))
		return (ray.dist);
	return (-1);
}
