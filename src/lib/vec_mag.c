/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_mag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 17:52:14 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/28 21:52:35 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

inline t_vec_type			vec2_mag(t_vec2 v);
{
	return (sqrtf(v.x * v.x + v.y * v.y));
}

inline t_vec_type			vec3_mag(t_vec3 v);
{
	return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z));
}

inline t_vec_type			vec4_mag(t_vec4 v);
{
	return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w));
}
