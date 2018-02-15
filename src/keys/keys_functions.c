/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 09:54:27 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/15 11:23:42 by mbeilles         ###   ########.fr       */
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
	uint32_t			flg;

	flg = SDL_WINDOW_FULLSCREEN_DESKTOP;
	if (SDL_GetWindowFlags(env->win) & flg)
	{
		printf(HD"Exiting fullscreen!\n");
		SDL_SetWindowFullscreen(env->win, 0);
	}
	else
	{
		printf(HD"Entering fullscreen!\n");
		SDL_SetWindowFullscreen(env->win, flg);
	}
	env->rpp_alt = env->rpp;
}

void					perspepective_up(t_env *env)
{
	if (env->pers < 100)
		env->pers *= 1.1;
	printf(HD"Perspective up %f\n"C_NRM, env->pers);
	env->rpp_alt = env->rpp;
}

void					perspepective_down(t_env *env)
{
	if (env->pers > 0)
		env->pers /= 1.1;
	printf(HD"Perspective down %f\n"C_NRM, env->pers);
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

void					expo_up(t_env *env)
{
	if (env->expo < 42)
		env->expo *= 1.01;
	env->rpp_alt = env->rpp;
}

void					expo_down(t_env *env)
{
	if (env->expo > 0)
		env->expo /= 1.01;
	env->rpp_alt = env->rpp;
}

void					threshold_up(t_env *env)
{
	if (env->rpp_threshold < 42)
		env->rpp_threshold++;
	env->rpp_alt = env->rpp;
	env->refresh = 1;
}

void					threshold_down(t_env *env)
{
	if (env->rpp_threshold > 1)
		env->rpp_threshold--;
	env->rpp_alt = env->rpp;
}
