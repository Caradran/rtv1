/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 03:58:39 by esuits            #+#    #+#             */
/*   Updated: 2018/02/22 20:50:45 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

t_cam	init_cam(t_vect org, t_vect look_at)
{
	t_cam	cam;
	t_vect	vect;

	cam.org = org;
	cam.frt = normal_vect(vect_sub(look_at, org));
	cam.dwn = normal_vect(vect_mult(init_vect(0.0, 1.0, 0.0), cam.frt));
	if (vect_mult_scale(cam.dwn, init_vect(0.0, 0.0, 1.0)) > 0.0)
		cam.dwn = vect_scale(-1.0, cam.dwn);
	if (norme_vect(cam.dwn) == 0.0)
	{
		cam.dwn = normal_vect(vect_mult(init_vect(1.0, 0.0, 0.0), cam.frt));
		if (vect_mult_scale(cam.dwn, init_vect(0.0, 0.0, 1.0)) > 0.0)
			cam.dwn = vect_scale(-1.0, cam.dwn);
	}
	cam.rgt = normal_vect(vect_mult(cam.frt, cam.dwn));
	return (cam);
}
