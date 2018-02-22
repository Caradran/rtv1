/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 06:54:14 by esuits            #+#    #+#             */
/*   Updated: 2018/02/22 20:46:11 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_col	interpolcol(t_col col1, t_col col2, double t)
{
	t_col col;

	col.r = col1.r * (1 - t) + col2.r * t;
	col.g = col1.g * (1 - t) + col2.g * t;
	col.b = col1.b * (1 - t) + col2.b * t;
	return (col);
}

t_lgt	init_lgt(t_col col, t_vect vect)
{
	t_lgt lgt;

	lgt.col = col;
	lgt.vect = vect;
	return (lgt);
}
