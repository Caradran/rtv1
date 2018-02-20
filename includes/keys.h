/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 09:10:24 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/17 21:13:43 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# include <SDL.h>
# include "rtv1.h"

# define KEY_MAX			11

typedef void				(t_key_func_proto)(t_env *env);
typedef void				(*t_key_func)(t_env *);

typedef struct				s_key
{
	uint32_t				keys;
	SDL_Scancode			*keycodes;
	t_key_func				func;
}							t_key;

t_key						*init_keys(void);

void						handle_keyboard(t_env *env);

uint32_t					is_combinason_pressed(t_key k, const uint8_t *keys);
SDL_Scancode				*create_codes(int32_t codes, ...);
t_key						create_key(uint32_t keys, SDL_Scancode *codes
										, t_key_func f);

t_key_func_proto			exit_rt;
t_key_func_proto			toggle_fullscreen;
t_key_func_proto			perspepective_up;
t_key_func_proto			perspepective_down;
t_key_func_proto			rpp_up;
t_key_func_proto			rpp_down;
t_key_func_proto			expo_up;
t_key_func_proto			expo_down;
t_key_func_proto			threshold_up;
t_key_func_proto			threshold_down;

#endif
