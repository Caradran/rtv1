/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:06:40 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/28 21:54:23 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

inline t_vec2			vec2_sub(t_vec2 a, t_vec2 b)
{
	return ((t_vec2){a.x - b.x, a.y - b.y});
}

inline t_vec3			vec3_sub(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){a.x - b.x, a.y - b.y, a.z - b.z});
}

inline t_vec4			vec4_sub(t_vec4 a, t_vec4 b)
{
	return ((t_vec4){a.w - b.w, a.x - b.x, a.y - b.y, a.z - b.z});
}
