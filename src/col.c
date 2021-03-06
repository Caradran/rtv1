/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 20:44:18 by esuits            #+#    #+#             */
/*   Updated: 2018/02/22 20:45:51 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		coltoi(t_col col)
{
	return ((((int)(col.r * 0xff0000)) & 0xff0000) +
			(((int)(col.g * 0xff00)) & 0xff00) +
			(((int)(col.b * 0xff)) & 0xff));
}

t_col	addcol(t_col col1, t_col col2)
{
	t_col col;

	col.r = col1.r + col2.r;
	if (col.r > 1)
		col.r = 1;
	col.g = col1.g + col2.g;
	if (col.g > 1)
		col.g = 1;
	col.b = col1.b + col2.b;
	if (col.b > 1)
		col.b = 1;
	return (col);
}

t_col	mult_scale_col(double t, t_col col)
{
	col.r = col.r * t;
	col.g = col.g * t;
	col.b = col.b * t;
	return (col);
}

t_col	multcol(t_col col1, t_col col2)
{
	t_col col;

	col.r = col1.r * col2.r;
	col.g = col1.g * col2.g;
	col.b = col1.b * col2.b;
	return (col);
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
