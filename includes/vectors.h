/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 15:08:02 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/29 07:43:41 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <math.h>
# include <unistd.h>
# include <stdint.h>
# include <math.h>

/*
** =============================================================================
** 		Typedefs
** =============================================================================
*/

typedef float			t_vec_type;

typedef struct			s_vec2
{
	t_vec_type			x;
	t_vec_type			y;
}						t_vec2;

typedef struct			t_vec3
{
	t_vec_type			x;
	t_vec_type			y;
	t_vec_type			z;
}						t_vec3;

typedef struct			s_w_vec4
{
	t_vec_type			w;
	t_vec_type			x;
	t_vec_type			y;
	t_vec_type			z;
}						t_vec4;

/*
** =============================================================================
** 		Functions
** =============================================================================
*/

t_vec2					vec2_mag(t_vec2 v);
t_vec3					vec3_mag(t_vec3 v);
t_vec4					vec4_mag(t_vec4 v);

t_vec2					vec2_inv(t_vec2 v);
t_vec3					vec3_inv(t_vec3 v);
t_vec4					vec4_inv(t_vec4 v);

t_vec2					vec2_add(t_vec2 a, t_vec2 b);
t_vec3					vec3_add(t_vec3 a, t_vec3 b);
t_vec3					vec4_add(t_vec4 a, t_vec4 b);

t_vec2					vec2_sub(t_vec2 a, t_vec2 b);
t_vec3					vec3_sub(t_vec3 a, t_vec3 b);
t_vec4					vec4_sub(t_vec4 a, t_vec4 b);

t_vec2					vec2_dot(t_vec2 a, t_vec2 b);
t_vec3					vec3_dot(t_vec3 a, t_vec3 b);
t_vec4					vec4_dot(t_vec4 a, t_vec4 b);

t_vec2					vec2_rot(t_vec2 v, t_vec_type theta);
t_vec3					vec3_rot(t_vec3 v, t_vec2 axis, t_vec_type theta);
t_vec4					vec4_rot(t_vec4 v, t_vec3 axis, t_vec_type theta);

t_vec2					vec2_norm(t_vec2 v);
t_vec3					vec3_norm(t_vec3 v);
t_vec4					vec4_norm(t_vec4 v);

t_vec2					vec2_scal(t_vec2 v, t_vec_type scal);
t_vec3					vec3_scal(t_vec3 v, t_vec_type scal);
t_vec4					vec4_scal(t_vec4 v, t_vec_type scal);

t_vec2					vec2_cross(t_vec2 a, t_vec2 b);
t_vec3					vec3_cross(t_vec3 a, t_vec3 b);
t_vec4					vec4_cross(t_vec4 a, t_vec4 b);

t_vec2					vec2_rot_q(t_vec2, t_vec4 axis, t_vec_type theta);
t_vec3					vec3_rot_q(t_vec3, t_vec4 axis, t_vec_type theta);
t_vec4					vec4_rot_q(t_vec4, t_vec4 axis, t_vec_type theta);

#endif
