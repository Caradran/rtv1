/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 20:57:13 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/22 22:17:03 by mbeilles         ###   ########.fr       */
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

static inline int32_t		update_scope(t_token *t, t_token_info *i
											, uint32_t token_number)
{
	uint32_t				n;
	uint32_t				changes;

	n = ~0U;
	changes = 0;
	while (++n < token_number)
	{
		if (t[n].state == LEXER_STATE_SCOPE_UP)
		{
			changes++;
			*scope += t.len;
		}
		if (t[n].state == LEXER_STATE_SCOPE_DOWN)
		{
			changes++;
			*scope -= t.len;
		}
	}
	return (changes);
}

/*
** 			sphere ( vector ( 0 0 0 ) 0.8 color ( 255 255 255 ) ) 
*/

uint32_t					parse_sphere(t_token t, t_token_info *i, t_env *env)
{
	t_token					tk[16];
	uint32_t				token_number;
	uint32_t				scope_changes;
	t_formes				f;

	get_sphere_tokens(i, t, &token_number, tk);
	if (token_number < 14)
		return (PARSER_ERROR_SYNTAX);
	if (update_scope(tk, i, token_number) != 6)
		return (PARSER_ERROR_SYNTAX);
	
	env->formes = create_sphere(env->formes, f.sph);
	return (PARSER_VALID);
}
