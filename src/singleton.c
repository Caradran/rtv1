/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 21:09:13 by esuits            #+#    #+#             */
/*   Updated: 2018/02/18 14:35:09 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_func_col		*intersection(void)
{
	static t_func_col func[3] = {&intersec_sphere, &intersec_plan, &intersec_cone};
	return (func);
}

t_func_double	*hit_shape(void)
{
	static t_func_double func[3] = {&hit_sphere, &hit_plan, &hit_cone};
	return (func);
}
