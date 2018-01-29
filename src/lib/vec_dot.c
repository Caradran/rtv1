/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_dot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:10:45 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/28 21:54:53 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

inline t_vec_type		vec2_dot(t_vec2 a, t_vec2 b);
{
	return (v.x * v.x + v.y * v.y);
}

inline t_vec_type		vec3_dot(t_vec3 a, t_vec3 b);
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

inline t_vec_type		vec4_dot(t_vec4 a, t_vec4 b);
{
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}
