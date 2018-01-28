/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 02:21:45 by esuits            #+#    #+#             */
/*   Updated: 2018/01/28 12:06:17 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_formes		*init_formes(t_env *env)
{
	t_formes	*formes;

	(void)env;
	if (!(formes = malloc(sizeof(t_formes))))
		return (NULL);
	formes->type = 1;
	formes->sph = init_sph(init_vect(1.4, 0.2, 0.2), 0.2, init_col(1, 1, 1, 1));
	if (!(formes->next = malloc(sizeof(t_formes))))
		return (NULL);
	formes->next->type = 1;
	formes->next->sph = init_sph(init_vect(1.4, -0.20, -0.2), 0.2,
			init_col(1, 0.75, 0.5, 1));
	if (!(formes->next->next = malloc(sizeof(t_formes))))
		return (NULL);
	formes->next->next->type = 2;
	formes->next->next->plan = init_plan(init_vect(0.1, 0.05, -0.05), 0.95,
			init_col(0.5, 0.5, 0.5, 0));
	if (!(formes->next->next->next = malloc(sizeof(t_formes))))
		return (NULL);
	formes->next->next->next->type = 2;
	formes->next->next->next->plan = init_plan(init_vect(0.1, -0.05, -0.05)
			, 0.95, init_col(0, 0, 0.8, 0));
	formes->next->next->next->next = NULL;
	return (formes);
}

t_lights		*init_lights(t_env *env)
{
	t_lights	*lights;

	(void)env;
	if (!(lights = malloc(sizeof(t_lights))))
		return (NULL);
	lights->lgt = init_lgt(init_col(1, 1, 1, 1), init_vect(1.3, 1, 0));
	lights->next = NULL;
	return (lights);
}