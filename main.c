/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 00:23:53 by esuits            #+#    #+#             */
/*   Updated: 2017/12/21 07:04:38 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		init_env(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_L, WIN_H, "rtv1");
	env->pimg = mlx_new_image(env->mlx, WIN_L, WIN_H);
	env->simg = (int *)mlx_get_data_addr(env->pimg, &(env->bpp), &(env->s_l),
				&(env->endian));
	env->cam = init_cam(init_vect(3, 1.5, -4), init_vect(0, 0, 0));
	return (1);
}

int		main(int argc, char **argv)
{
	t_env env;

	if (!init_env(&env))
		return (0);
	write(1, "rendering...\n", 13);
	return (0);
}
