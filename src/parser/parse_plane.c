/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:31:33 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/25 03:44:00 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static inline t_formes		*create_plane(t_formes *next, t_plan plane)
{
	t_formes				*f;

	if (!(f = (t_formes*)malloc(sizeof(t_formes))))
		exit(EXIT_FAILURE);
	f->plan = plane;
	f->plan.nrml = normal_vect(f->plan.nrml);
	f->next = next;
	f->type = 2;
	return (f);
}

/*
** 			plane(pos(0, 0, 0), 0.8, color(0.7, 0.3, 1, 1))
*/

uint32_t					parse_plane(t_token t, t_token_info *i, t_env *env)
{
	static uint32_t			token_number[3] = {0, 18, 6};
	t_token					tk[18];
	uint32_t				n;
	uint32_t				ret;
	t_formes				f;

	if (get_tokens(i, t, token_number, tk) || token_number[0] < 15)
		return (PARSER_ERROR_SYNTAX);
	n = ~0U;
	ret = PARSER_VALID;
	while (++n < token_number[0])
	{
		if (tk[n].state == LEXER_STATE_OBJECT && ft_strnequ(tk[n].str
					, "normal", 3))
			ret = parse_vector(tk + n, 6, &(f.plan.nrml), &n);
		if (tk[n].state == LEXER_STATE_OBJECT && ft_strnequ(tk[n].str
					, "color", 5))
			ret = parse_color(tk + n, 7, &(f.plan.col), &n);
		if (tk[n].state == LEXER_STATE_PARAMETER_NUMBER)
			ret = parse_number(tk[n], &(f.plan.dst), &n);
		if (ret != PARSER_VALID)
			return (ret);
	}
	env->formes = create_plane(env->formes, f.plan);
	return (PARSER_VALID);
}
