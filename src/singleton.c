/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 21:09:13 by esuits            #+#    #+#             */
/*   Updated: 2018/02/22 20:05:06 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_func_col		*intersection(void)
{
	static t_func_col func[4] = {&intersec_sphere,
		&intersec_plan, &intersec_cone, &intersec_cyl};

	return (func);
}

t_func_double	*hit_shape(void)
{
	static t_func_double func[4] = {&hit_sphere, &hit_plan, &hit_cone,
		&hit_cyl};

	return (func);
}
