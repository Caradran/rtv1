/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_layer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 20:49:06 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/31 09:30:47 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "matrice.h"

#define RPP 8/*1U << 0*/

void				set_pixels(SDL_Surface *s, uint32_t x, uint32_t y, int32_t rpp, t_col color)
{
	int32_t		rp;
	int32_t		ro;
	int32_t		rpp_alt;

	rpp_alt = ((rpp >> 1)) - (int32_t)rpp - 1;
	rpp >>= 1;
	rp = rpp_alt;
	while (++rp < rpp)
	{
		ro = rpp_alt;
		while (++ro < rpp)
			if (rp + x + (ro + y) * s->w < s->w * s->h)
				((uint32_t*)s->pixels)[x + rp + (ro + y) * s->w] = coltoi(color);
	}
}

void				raycast_calculate_surface(t_env *env)
{
	t_ray			ray;
	SDL_Surface		*s;
	uint32_t		x;
	uint32_t		y;

	s = env->surface;
	y = 0.0;
	while (y < (t_vec_type)s->h + (env->rpp + 1) / 2)
	{
		x = 0.0;
		while (x < (t_vec_type)s->w)
		{
			ray = init_ray(vect_add(vect_add(vect_scale((x - s->w / 2.0) / s->h, env->cam.dwn),
							vect_scale((y - s->h / 2.0) / s->h, env->cam.rgt)), env->cam.org), env->cam.frt);
			set_pixels(s, x, y, (int32_t)env->rpp, send_ray(&ray, env));
			x += env->rpp;
		}
		y += env->rpp;
	}
}
