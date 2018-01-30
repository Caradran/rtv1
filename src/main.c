/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 00:23:53 by esuits            #+#    #+#             */
/*   Updated: 2018/01/30 23:16:36 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include "rtv1.h"
#include <stdio.h>

int		init_env(t_env *env)
{
	if (!(env->win = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED
	, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
		exit(EXIT_FAILURE);
	env->surface = SDL_GetWindowSurface(env->win);
	env->cam = init_cam(init_vect(0, 0, 0), init_vect(1, 0, 0));
	env->formes = init_formes(env);
	env->lights = init_lights(env);
	return (1);
}

void	send_rays(t_env *env)
{
	uint32_t		x;
	uint32_t		y;
	double			tmpx;
	double			tmpy;
	t_ray			ray;

	x = ~0U;
	while (++x < env->surface->w)
	{
		y = ~0U;
		while (++y < env->surface->h)
		{
			tmpx = (double)(x - env->surface->w / 2.0) / env->surface->h;
			tmpy = (double)(y - env->surface->h / 2.0) / env->surface->h;
			ray = init_ray(vect_add(vect_add(vect_scale(tmpx, env->cam.dwn),
						vect_scale(tmpy, env->cam.rgt)), env->cam.org), env->cam.frt);
			((int*)env->surface->pixels)[y * env->surface->w + x] = coltoi(send_ray(&ray, env));
		}
	}
}

int		main(int argc, char **argv)
{
	uint32_t			quit;
	t_env				env;
	SDL_Event			e;

	if (!SDL_Init(SDL_INIT_VIDEO) && !init_env(&env))
		exit(EXIT_FAILURE);
	write(1, "rendering...\n", 13);
	send_rays(&env);
	quit = 0;
	while (!quit)
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				exit(EXIT_SUCCESS);
			SDL_UpdateWindowSurface(env.win);
			if (e.type == SDL_QUIT)
				quit = 1;
		}
	return (0);
}
