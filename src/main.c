/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 00:23:53 by esuits            #+#    #+#             */
/*   Updated: 2018/02/24 22:16:37 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include "rtv1.h"
#include "keys.h"
#include "parser.h"
#include <stdio.h>

t_env					*get_env(void)
{
	static t_env		env;

	return (&env);
}

static int				draw(void *data)
{
	ft_putstr(STR_INF("Draw thread started\n"));
	while (!(get_env()->quit))
	{
		if (get_env()->refresh)
		{
			get_env()->surface = SDL_GetWindowSurface(get_env()->win);
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

static void				leave(char *s, uint32_t exit_code)
{
	if (s)
		ft_putstr(s);
	ft_putstr(HD"Exiting "NICK"...\n"C_NRM);
	exit(exit_code);
}

static int				init_env(t_env *env, int c, char **v)
{
	if (!(env->win = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED
			, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN
			| SDL_WINDOW_RESIZABLE)))
		exit(EXIT_FAILURE);
	env->surface = SDL_GetWindowSurface(env->win);
	env->cam = init_cam(init_vect(0, 0, 0), init_vect(1, 0, 0));
	env->formes = NULL;
	env->lights = NULL;
	if (c < 2)
		leave(STR_ERR("001", "Scene not specified. Usage: rtv1 file_path\n")
			, EXIT_SUCCESS);
	if ((parse_file(v[1], env)) != PARSER_VALID)
		leave(HD"Parser exited with error syntax\n"C_NRM, EXIT_SUCCESS);
	env->rpp = 21;
	env->rpp_alt = 21;
	env->rpp_threshold = 1;
	env->refresh = 1;
	env->pers = 1.0;
	env->expo = 4 * M_PI;
	return (1);
}

int						main(int c, char **v)
{
	SDL_Thread			*t;
	SDL_Event			e;

	if (!SDL_Init(SDL_INIT_VIDEO) && !init_env(get_env(), c, v))
		exit(EXIT_FAILURE);
	if (!(t = SDL_CreateThread(draw, "Draw thread", NULL)))
		exit(EXIT_FAILURE);
	while (!get_env()->quit)
	{
		while (SDL_PollEvent(&e))
		{
			handle_keyboard(get_env());
			if (e.type == SDL_WINDOWEVENT
					&& e.window.event == SDL_WINDOWEVENT_RESIZED)
			{
				get_env()->rpp_alt = get_env()->rpp;
				get_env()->refresh = 1;
			}
			if (e.type == SDL_QUIT)
				exit(EXIT_SUCCESS);
		}
	}
	return (0);
}
