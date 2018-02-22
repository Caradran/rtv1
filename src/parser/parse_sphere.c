/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 20:57:13 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/22 22:43:56 by mbeilles         ###   ########.fr       */
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

static inline void			get_sphere_tokens(t_token_info *i, t_token t
												, uint32_t *n, t_token *tk)
{
	*n = ~0U;
	tk[0] = t;
	while (++*n < 15)
	{
		tk[*n] = get_next_token(i);
		if (tk[*n].state == LEXER_STATE_MAX)
			return ;
	}
}

/*
** 			sphere ( pos ( 0 0 0 ) 0.8 color ( 255 255 255 ) )
*/

uint32_t					parse_sphere(t_token t, t_token_info *i, t_env *env)
{
	t_token					tk[16];
	uint32_t				token_number;
	uint32_t				n;
	uint32_t				ret;
	t_formes				f;

	get_sphere_tokens(i, t, &token_number, tk);
	if (token_number < 14 || update_scope(tk, i, token_number) != 6)
		return (PARSER_ERROR_SYNTAX);
	n = ~0U;
	while (++n > 0)
	{
		if (tk[n].state == LEXER_STATE_OBJECT && ft_strequ(tk[n].str, "pos"))
			ret = parse_vector(tk[n], i, &(f.sph.ctr));
		if (tk[n].state == LEXER_STATE_OBJECT && ft_strequ(tk[n].str, "color"))
			ret = parse_color(tk[n], i, &(f.sph.col));
		if (tk.[n].state == LEXER_STATE_PARAMETER_NUMBER)
			ret = parse_number(tk[n], &(f.sph.r));
		if (ret == PARSER_ERROR_SYNTAX)
			return (PARSER_ERROR_SYNTAX);
	}
	f.sph.ctr = parse_vector();
	env->formes = create_sphere(env->formes, f.sph);
	return (PARSER_VALID);
}
