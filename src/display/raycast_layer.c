/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_layer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 20:49:06 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/11 15:01:32 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "matrice.h"

#define RPP 8 /*1U << 0*/

void				set_pixels(SDL_Surface *s, uint32_t x, uint32_t y, int32_t rpp, t_col color)
{
	int32_t		rp;
	int32_t		ro;
	int32_t		rpp_alt;

	rpp_alt = ((rpp >> 1)) - (int32_t)rpp - 1;
	rpp = (rpp >> 1) + 2;
	rp = rpp_alt;
	while (++rp < rpp)
	{
		ro = rpp_alt;
		while (++ro < rpp)
			if (rp + x + (ro + y) * s->w < s->w * s->h && rp + x < s->w && ro + y < s->h)
				((uint32_t*)s->pixels)[x + rp + (ro + y) * s->w] = coltoi(color);
	}
}

void				raycast_calculate_surface(t_env *env, uint32_t rpp)
{
	t_ray			ray;
	SDL_Surface		*s;
	int32_t			x;
	int32_t			y;

	s = env->surface;
	y = -rpp;
	while (y < (t_vec_type)s->h + rpp)
	{
		x = -rpp;
		while (x < (t_vec_type)s->w + rpp)
		{
			ray = init_ray(vect_add(vect_add(vect_scale((x - s->w / 2.0) / s->h, env->cam.rgt),
							vect_scale((y - s->h / 2.0) / s->h, env->cam.dwn)), env->cam.org), rot_vect(rot_vect(env->cam.frt, (/*(FOV / 2.0)*/ - (FOV / s->w * (double)x)), env->cam.dwn), (/*(FOV_H / 2.0)*/ - (FOV_H / s->h * (double)y)), env->cam.rgt));
			/*ray = init_ray(vect_add(vect_add(vect_scale((x - s->w / 2.0) / s->h, env->cam.rgt),*/
							/*vect_scale((y - s->h / 2.0) / s->h, env->cam.dwn)), env->cam.org), env->cam.frt);*/
			set_pixels(s, x, y, (int32_t)rpp, send_ray(&ray, env));
			x += rpp;
		}
		y += rpp;
	}
}
