/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 23:18:24 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/28 23:21:59 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

inline t_vec2			vec2_norm(t_vec2 v)
{
	return (vec2_scal(v, 1.0 / vec2_mag(v));
}

inline t_vec3			vec3_norm(t_vec3 v)
{
	return (vec3_scal(v, 1.0 / vec3_mag(v));
}

inline t_vec4			vec4_norm(t_vec4 v)
{
	return (vec4_scal(v, 1.0 / vec4_mag(v));
}
