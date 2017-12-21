/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 06:54:14 by esuits            #+#    #+#             */
/*   Updated: 2017/12/21 07:16:52 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_col	init_col(double r, double g, double b, double s)
{
	t_col col;

	col.r = r;
	col.g = g;
	col.b = b;
	col.s = s;
	return (col);
}

t_lgt	init_lgt(t_col col, t_vect vect)
{
	t_lgt lgt;

	lgt.col = col;
	lgt.vect = vect;
	return (lgt);
}
