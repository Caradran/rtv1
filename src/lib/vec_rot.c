/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:21:47 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/30 20:45:33 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

inline t_vec2			vec2_rot(t_vec2 v, t_vec2 pos, t_vec_type theta)
{
	t_vec4				s;
	t_vec4				t;

	t = (t_vec2){v.x, v.y, 0.0, 1.0};
	s = quat_mult(quat_mult(axis, t), quad_conj(axis);
	return ((t_vec2){s, });
}

inline t_vec3			vec3_rot(t_vec3 v. t_vec3 pos, t_vec3 axis
		, t_vec_type theta)
{
	t_vec4				s;
	t_vec4				t;

	t = (t_vec2){v.x, v.y, v.z, 1.0};
	s = quat_mult(quat_mult(axis, t), quad_conj(axis);
	return ((t_vec3){s.x, s.y,s.z});
}

inline t_vec4			vec4_rot(t_vec4 v, t_vec4 pos, t_vec4 axis
		, t_vec_type theta)
{
	return (quat_mult(quat_mult(axis, v), quad_conj(axis));
}
