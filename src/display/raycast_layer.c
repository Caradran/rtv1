/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_layer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 20:49:06 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/24 22:14:34 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "matrice.h"

static inline void	set_pixels(uint32_t x, uint32_t y, int32_t rpp, t_col col)
{
	int32_t			rp;
	int32_t			ro;
	SDL_Surface		*s;

	rp = ~0U;
	s = (get_env())->surface;
	while (++rp < rpp)
	{
		ro = ~0U;
		while (++ro < rpp)
			if ((rp + x < s->w) && (ro + y < s->h))
				((uint32_t*)s->pixels)[x + rp + (ro + y) * s->w] = coltoi(col);
	}
}

static inline t_ray	calculate_ray(int32_t x, int32_t y, t_env *env)
{
	SDL_Surface		*s;
	t_ray			ray;

	s = env->surface;
	ray = init_ray(
			vect_add(
				vect_add(
					vect_scale((x - (s->w / 2.0)) / s->h, env->cam.rgt)
					, vect_scale((y - (s->h / 2.0)) / s->h, env->cam.dwn))
				, env->cam.org),
			normal_vect(
				vect_sub(
					vect_scale(env->pers, env->cam.frt)
					, vect_sub(env->cam.org
					, vect_add(
						vect_add(
							vect_scale((x - (s->w / 2.0)) / s->h, env->cam.rgt)
							, vect_scale((y - s->h / 2.0) / s->h, env->cam.dwn))
					, env->cam.org)))));
	return (ray);
}

void				raycast_calculate_surface(t_env *env, uint32_t rpp)
{
	SDL_Surface		*s;
	int32_t			x;
	int32_t			y;

	s = env->surface;
	y = 0;
	while (y < s->h)
	{
		x = 0;
		while (x < s->w)
		{
			set_pixels(x, y, (int32_t)rpp
	, send_ray(calculate_ray(x + (rpp >> 1), y + (rpp >> 1), env), env));
			x += rpp;
		}
		y += rpp;
	}
}
