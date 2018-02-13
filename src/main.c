/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 00:23:53 by esuits            #+#    #+#             */
/*   Updated: 2018/02/13 18:34:46 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include "rtv1.h"
#include "keys.h"
#include <stdio.h>

t_env					*get_env(void)
{
	static t_env		env;

	return (&env);
}

static int				draw(void *data)
{
	printf(HD"Draw thread started\n"C_NRM);
	while (!(get_env()->quit))
	{
		if (get_env()->refresh)
		{
			raycast_calculate_surface(get_env(), get_env()->rpp_alt);
			SDL_UpdateWindowSurface(get_env()->win);
			if (get_env()->rpp_alt > get_env()->rpp_threshold)
				get_env()->rpp_alt--;
			else
				get_env()->refresh = 0;
		}
	}
	return (0);
}

static int				init_env(t_env *env)
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
	env->rpp_threshold = 5;
	env->pers = 1;
	env->refresh = 1;
	return (1);
}

int						main()
{
	SDL_Thread			*t;
	SDL_Event			e;

	if (!SDL_Init(SDL_INIT_VIDEO) && !init_env(get_env()))
		exit(EXIT_FAILURE);
	if (!(t = SDL_CreateThread(draw, "Draw thread", NULL)))
		exit(EXIT_FAILURE);
	while (!get_env()->quit)
	{
		while (SDL_PollEvent(&e))
		{
			handle_keyboard(get_env());
			if (e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_RESIZED)
				get_env()->surface = SDL_GetWindowSurface(get_env()->win), get_env()->refresh = 1;
			if (e.type == SDL_QUIT)
				exit(EXIT_SUCCESS);
		}
	}
	return (0);
}
