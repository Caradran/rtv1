/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:32:37 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/24 22:11:50 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** 			cam(pos(10, 0, 0), look_at(0, 0, 0))
*/

uint32_t					parse_cam(t_token t, t_token_info *i, t_env *env)
{
	static uint32_t			token_number[3] = {0, 14, 6};
	t_token					tk[15];
	uint32_t				n;
	uint32_t				ret;
	t_vect					v[2];

	if (get_tokens(i, t, token_number, tk) || token_number[0] < 13)
		return (PARSER_ERROR_SYNTAX);
	n = ~0U;
	ret = PARSER_VALID;
	while (++n < token_number[0])
	{
		if (tk[n].state == LEXER_STATE_OBJECT && ft_strnequ(tk[n].str
					, "pos", 3))
			ret = parse_vector(tk + n, 6, v, &n);
		if (tk[n].state == LEXER_STATE_OBJECT && ft_strnequ(tk[n].str
					, "look_at", 3))
			ret = parse_vector(tk + n, 6, v + 1, &n);
		if (ret != PARSER_VALID)
			return (ret);
	}
	env->cam = init_cam(v[0], v[1]);
	return (PARSER_VALID);
}
