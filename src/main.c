/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 00:23:53 by esuits            #+#    #+#             */
/*   Updated: 2018/01/28 03:11:51 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

int		init_env(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_L, WIN_H, "rtv1");
	env->pimg = mlx_new_image(env->mlx, WIN_L, WIN_H);
	env->simg = (int *)mlx_get_data_addr(env->pimg, &(env->bpp), &(env->s_l),
				&(env->endian));
	env->cam = init_cam(init_vect(0, 0, 0), init_vect(1, 0, 0));
	env->formes = init_formes(env);
	env->lights = init_lights(env);
	return (1);
}

void	send_rays(t_env *env)
{
	int		x;
	int		y;
	double	tmpx;
	double	tmpy;
	t_ray ray;

	x = -1;
	while (++x < WIN_L && (y = -1))
		while (++y < WIN_H)
		{
			tmpx = (double)(x - WIN_L / 2) / WIN_L;
			tmpy = (double)(y - WIN_H / 2) / WIN_H;
			ray = init_ray(vect_add(vect_add(vect_scale(tmpx, env->cam.dwn),
						vect_scale(tmpy, env->cam.rgt)), env->cam.org), env->cam.frt);
			env->simg[y * WIN_L + x] = coltoi(send_ray(&ray, env));
		}
}

int		main(int argc, char **argv)
{
	t_env env;

	(void)argc;
	(void)argv;
	if (!init_env(&env))
		return (0);
	write(1, "rendering...\n", 13);
	send_rays(&env);
	mlx_put_image_to_window(NULL, env.win, (char *)env.pimg, 0, 0);
	mlx_loop(env.mlx);
	return (0);
}
