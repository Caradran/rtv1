/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 23:23:36 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/28 23:26:10 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

inline t_vec2			vec2_scal(t_vec2 a, t_vec_type s)
{
	return ((t_vec2){v.x * s, v.y * s});
}

inline t_vec3			vec3_scal(t_vec3 a, t_vec_type s)
{
	return ((t_vec3){v.x * s, v.y * s, v.z * s});
}

inline t_vec4			vec4_scal(t_vec4 a, t_vec_type s)
{
	return ((t_vec4){v.w * s, v.x * s, v.y * s, v.z * s});
}
