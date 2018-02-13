/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 09:54:27 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/13 13:07:19 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

void					exit_rt(t_env *env)
{
	printf(HD"Exiting "NICK"!\n");
	exit(EXIT_SUCCESS);
}

void					toggle_fullscreen(t_env *env)
{
	printf(HD"Exiting fullscreen!\n");
	SDL_SetWindowFullscreen(env->win, 0);
}

void					perspepective_up(t_env *env)
{
	if (env->pers < 100)
		env->pers *= 1.1;
	env->rpp_alt = env->rpp;
}

void					perspepective_down(t_env *env)
{
	if (env->pers > 0)
		env->pers /= 1.1;
	env->rpp_alt = env->rpp;
}

void					rpp_up(t_env *env)
{
	if (env->rpp < 42)
		env->rpp++;
	env->rpp_alt = env->rpp;
}

void					rpp_down(t_env *env)
{
	if (env->rpp > 1)
		env->rpp--;
	env->rpp_alt = env->rpp;
}
