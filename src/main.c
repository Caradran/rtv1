/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 00:23:53 by esuits            #+#    #+#             */
/*   Updated: 2018/02/11 12:01:56 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include "rtv1.h"
#include <stdio.h>

int		init_env(t_env *env)
{
	if (!(env->win = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED
	, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)))
		exit(EXIT_FAILURE);
	env->surface = SDL_GetWindowSurface(env->win);
	env->cam = init_cam(init_vect(0, 0, 0), init_vect(1, 0, 0));
	env->formes = init_formes(env);
	env->lights = init_lights(env);
	env->rpp = 1;
	return (1);
}

int		main(int argc, char **argv)
{
	uint32_t			quit;
	uint32_t			rpp;
	t_env				env;
	SDL_Event			e;

	if (!(quit = 0) && !SDL_Init(SDL_INIT_VIDEO) && !init_env(&env))
		exit(EXIT_FAILURE);
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			rpp = env.rpp;
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					exit(EXIT_SUCCESS);
				if (e.key.keysym.scancode == SDL_SCANCODE_DOWN)
					(env.rpp < 42) ? env.rpp++ : NULL;
				if (e.key.keysym.scancode == SDL_SCANCODE_UP)
					(env.rpp > 1) ? env.rpp-- : NULL;
			}
			if (e.type == SDL_QUIT)
				quit = 1;
		}
		if (rpp > 3)
			rpp--;
		raycast_calculate_surface(&env, rpp);
		SDL_UpdateWindowSurface(env.win);
	}
	return (0);
}
