/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:35:32 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/24 22:11:34 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static inline t_formes		*create_cylinder(t_formes *next, t_cyl cylinder)
{
	t_formes				*f;

	if (!(f = (t_formes*)malloc(sizeof(t_formes))))
		exit(EXIT_FAILURE);
	f->cyl = cylinder;
	f->next = next;
	f->type = 4;
	return (f);
}

/*
** 			cylinder(pos(0, 0, 0), dir(0, 1, 0), 0.8, color(0.5, 0.7, 1, 1))
*/

uint32_t					parse_cylinder(t_token t, t_token_info *i
											, t_env *env)
{
	static uint32_t			token_number[3] = {0, 23, 8};
	t_token					tk[32];
	uint32_t				n;
	uint32_t				ret;
	t_formes				f;

	if (get_tokens(i, t, token_number, tk) || token_number[0] < 21)
		return (PARSER_ERROR_SYNTAX);
	n = ~0U;
	ret = PARSER_VALID;
	while (++n < token_number[0])
	{
		if (tk[n].state == 1 << 4 && ft_strnequ(tk[n].str, "pos", 3))
			ret = parse_vector(tk + n, 6, &(f.cyl.pos), &n);
		if (tk[n].state == 1 << 4 && ft_strnequ(tk[n].str, "dir", 3))
			ret = parse_vector(tk + n, 6, &(f.cyl.dir), &n);
		if (tk[n].state == 1 << 4 && ft_strnequ(tk[n].str, "color", 5))
			ret = parse_color(tk + n, 7, &(f.cyl.col), &n);
		if (tk[n].state == LEXER_STATE_PARAMETER_NUMBER)
			ret = parse_number(tk[n], &(f.cyl.r), &n);
		if (ret != PARSER_VALID)
			return (ret);
	}
	env->formes = create_cylinder(env->formes, f.cyl);
	return (PARSER_VALID);
}
