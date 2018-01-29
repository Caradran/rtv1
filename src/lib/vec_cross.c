/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cross.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 23:30:07 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/29 04:42:54 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

inline t_vec2			vec2_cross(t_vec2 a, t_vec2 b)
{
	return ((t_vec2){a.y * b.x - a.x * b.x
					, a.x * b.y - a.y * b.x});
}

inline t_vec3			vec3_cross(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){a.y * b.z - b.y * a.z
					, a.z * b.x - b.z * a.x
					, a.x * b.y - b.x * a.y});
}

inline t_vec4			vec4_cross(t_vec4 a, t_vec4 b)
{
	return ((t_vec4){a.x * b.y - a.y * b.x
					, a.y * b.z - a.z * b.y
					, a.z * b.w - a.w * b.z
					, a.w * b.x - a.x * b.w});
}
