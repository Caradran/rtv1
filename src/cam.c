/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 03:58:39 by esuits            #+#    #+#             */
/*   Updated: 2018/01/31 04:02:59 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

t_cam	init_cam(t_vect org, t_vect look_at)
{
	t_cam cam;

	cam.org = org;
	cam.frt = normal_vect(vect_sub(look_at, org));
	cam.dwn = init_vect(0.0, 0.0, -1.0);
	cam.rgt = init_vect(0.0, 1.0, 0.0);
	return (cam);
}
