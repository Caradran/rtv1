/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_inv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:01:10 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/28 21:53:17 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

inline t_vec2			vec2_inv(t_vec2 v)
{
	return ((t_vec2){-v.x, -v.y});
}

inline t_vec3			vec3_inv(t_vec3 v)
{
	return ((t_vec2){-v.x, -v.y, -v.z});
}

inline t_vec4			vec4_inv(t_vec4 v)
{
	return ((t_vec2){-v.w, -v.x, -v.y, -v.z});
}
