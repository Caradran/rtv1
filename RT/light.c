/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 06:54:14 by esuits            #+#    #+#             */
/*   Updated: 2018/01/25 17:50:21 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		coltoi(t_col col)
{
	return ((((int)(col.r * 0xff0000)) & 0xff0000) + 
			(((int)(col.g * 0xff00)) & 0xff00) +
			(((int)(col.b * 0xff)) & 0xff));
}


t_col	init_col(double r, double g, double b, double s)
{
	t_col col;

	col.r = r;
	col.g = g;
	col.b = b;
	col.s = s;
	return (col);
}

t_col	interpolcol(t_col col1, t_col col2, double t)
{
	t_col col;

	col.r = col1.r * (1 - t) + col2.r * t;
	col.g = col1.g * (1 - t) + col2.g * t;
	col.b = col1.b * (1 - t) + col2.b * t;
	col.s = col1.s * (1 - t) + col2.s * t;
	return (col);
}

t_lgt	init_lgt(t_col col, t_vect vect)
{
	t_lgt lgt;

	lgt.col = col;
	lgt.vect = vect;
	return (lgt);
}
