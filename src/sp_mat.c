/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_mat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 02:18:14 by esuits            #+#    #+#             */
/*   Updated: 2017/12/21 04:54:49 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_mat	rot_mat(t_vect *v, double theta)
{
	t_mat rot;

	if (!(init_mat(&rot, 3, 3)))
		return (rot);
	rot.mat[0][0] = cos(theta) + v->x * v->x * (1 - cos(theta));
	rot.mat[1][1] = cos(theta) + v->y * v->y * (1 - cos(theta));
	rot.mat[2][2] = cos(theta) + v->z * v->z * (1 - cos(theta));
	rot.mat[0][1] = v->x * v->y * (1 - cos(theta)) - v->z * sin(theta);
	rot.mat[0][2] = v->x * v->z * (1 - cos(theta)) + v->y * sin(theta);
	rot.mat[1][0] = v->x * v->y * (1 - cos(theta)) + v->z * sin(theta);
	rot.mat[1][2] = v->z * v->y * (1 - cos(theta)) - v->x * sin(theta);
	rot.mat[2][0] = v->x * v->z * (1 - cos(theta)) - v->y * sin(theta);
	rot.mat[2][1] = v->z * v->y * (1 - cos(theta)) + v->x * sin(theta);
	return (rot);
}

t_mat	id_mat(void)
{
	t_mat id;

	if (!(init_mat(&id, 3, 3)))
		return (id);
	id.mat[0][0] = 1;
	id.mat[0][0] = 1;
	id.mat[0][0] = 1;
	return (id);
}