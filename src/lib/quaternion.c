/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 08:08:54 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/29 08:33:31 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

inline t_vec4			quat_mult(t_vec4 a, t_vec_type scal)
{
	return ((t_vec4){a.w * scal, a.x * scal, a.y * scal, a.z * scal});
}

inline t_vec4			quad_conj(t_vec4 a)
{
	return ((t_vec4){a.w, -a.x, -a.y, -a.z});
}

inline t_vec4			quat_add(t_vec4 a, t_vec_type scal)
{
	return ((t_vec4){a.w + scal, a.x, a.y, a.z});
}

inline t_vec4			quat_add(t_vec4 a, t_vec4 b)
{
	return ((t_vec4){a.w + b.w, a.x + b.x, a.y + b.y, a.z + b.z});
}

inline t_vec4			quat_mult(t_vec4 a, t_vec_4 b)
{
	return ((t_vec4){a.w * b.w − a.x * b.x − a.y * b.y − a.z * b.z
					, a.w * b.x + a.x * b.w + a.y * b.z − a.z * b.y
					, a.w * b.y − a.x * b.z + a.y * b.w + a.z * b.x
					, a.w * b.z + a.x * b.y − a.y * b.x + a.z * b.w});
}
