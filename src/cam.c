/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 03:58:39 by esuits            #+#    #+#             */
/*   Updated: 2018/02/18 17:03:11 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

t_cam	init_cam(t_vect org, t_vect look_at)
{
	t_cam cam;

	cam.org = org;
	cam.frt = normal_vect(vect_sub(look_at, org));
	cam.dwn = normal_vect(vect_mult(init_vect(0, 1, 0), cam.frt));
	if (norme_vect(cam.dwn) == 0)
		cam.dwn = normal_vect(vect_mult(init_vect(1, 0, 0), cam.frt));
	cam.rgt = normal_vect(vect_mult(cam.frt, cam.dwn));
	return (cam);
}
