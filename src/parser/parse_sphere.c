/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 20:57:13 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/23 07:52:28 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static inline t_formes		*create_sphere(t_formes *next, t_sph sphere)
{
	t_formes				*f;

	if (!(f = (t_formes*)malloc(sizeof(t_formes))))
		exit(EXIT_FAILURE);
	f->sph = sphere;
	f->next = next;
	f->type = 1;
	return (f);
}

/*
** 			sphere(pos(10, 0, 0), 0.8, color(1, 1, 1, 1))
*/

uint32_t					parse_sphere(t_token t, t_token_info *i, t_env *env)
{
	static uint32_t			token_number[3] = {0, 18, 6};
	t_token					tk[32];
	uint32_t				n;
	uint32_t				ret;
	t_formes				f;

	if (get_tokens(i, t, token_number, tk) || token_number[0] < 15)
		return (PARSER_ERROR_SYNTAX);
	n = ~0U;
	ret = PARSER_VALID;
	while (++n < token_number[0])
	{
		printf(HD"Token: '%.*s'\n", tk[n].len, tk[n].str);
		if (tk[n].state == LEXER_STATE_OBJECT && ft_strnequ(tk[n].str, "pos", 3))
			ret = parse_vector(tk + n, 6, &(f.sph.ctr), &n);
		if (tk[n].state == LEXER_STATE_OBJECT && ft_strnequ(tk[n].str, "color", 5))
			ret = parse_color(tk + n, 7, &(f.sph.col), &n);
		if (tk[n].state == LEXER_STATE_PARAMETER_NUMBER)
			ret = parse_number(tk[n], &(f.sph.r), &n);
		if (ret != PARSER_VALID)
		{
			printf(C_RED"Error\n"C_NRM);
			return (ret);
		}
	}
	env->formes = create_sphere(env->formes, f.sph);
	return (PARSER_VALID);
}
