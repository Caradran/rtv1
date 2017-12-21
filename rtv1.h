/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 00:33:28 by esuits            #+#    #+#             */
/*   Updated: 2017/12/21 05:08:00 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include "matrice.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*pimg;
	int		*simg;
	int		bpp;
	int		s_l;
	int		endian;
	t_cam	cam;
}				t_env;

# define WIN_L 1000
# define WIN_H 1000
#endif
