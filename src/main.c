/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 00:23:53 by esuits            #+#    #+#             */
/*   Updated: 2018/02/13 13:19:13 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include "rtv1.h"
#include "keys.h"
#include <stdio.h>

int						init_env(t_env *env)
{
	if (!(env->win = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED
	, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)))
		exit(EXIT_FAILURE);
	env->surface = SDL_GetWindowSurface(env->win);
	env->cam = init_cam(init_vect(0, 0, 0), init_vect(1, 0, 0));
	env->formes = init_formes(env);
	env->lights = init_lights(env);
	env->rpp = 4;
	env->rpp_alt = 16;
	env->pers = 1;
	return (1);
}

int						main()
{
	uint32_t			quit;
	t_env				env;
	SDL_Event			e;

	if (!(quit = 0) && !SDL_Init(SDL_INIT_VIDEO) && !init_env(&env))
		exit(EXIT_FAILURE);
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			handle_keyboard(&env);
			if (e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_RESIZED)
				env.surface = SDL_GetWindowSurface(env.win);
			if (e.type == SDL_QUIT)
				quit = 1;
		}
		if (env.rpp_alt > 5)
			env.rpp_alt--;
		raycast_calculate_surface(&env, env.rpp_alt);
		SDL_UpdateWindowSurface(env.win);
	}
	return (0);
}
