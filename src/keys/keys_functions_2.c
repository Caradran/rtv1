/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 21:22:38 by esuits            #+#    #+#             */
/*   Updated: 2018/02/22 21:24:36 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
