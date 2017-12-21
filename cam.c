/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 03:58:39 by esuits            #+#    #+#             */
/*   Updated: 2017/12/21 06:54:07 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cam	init_cam(t_vect org, t_vect look_at)
{
	t_cam cam;

	cam.org = org;
	cam.frt = normal_vect(vect_add(org, vect_scale(-1, look_at)));
	cam.rgt = normal_vect(vect_mult(init_vect(0, 1, 0), cam.frt));
	cam.dwn = normal_vect(vect_mult(cam.rgt, cam.frt));
	return (cam);
}
