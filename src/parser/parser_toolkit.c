/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_toolkit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 22:28:58 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/24 22:04:01 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

inline int32_t				update_scope(t_token *t, t_token_info *i
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
			changes += t[n].len;
			i->scope += t[n].len;
		}
		if (t[n].state == LEXER_STATE_SCOPE_DOWN)
		{
			changes += t[n].len;
			i->scope -= t[n].len;
		}
	}
	return (changes);
}

inline uint32_t				get_tokens(t_token_info *i, t_token t
										, uint32_t *n, t_token *tk)
{
	uint32_t				scope;

	*n = 0;
	scope = 0;
	tk[0] = t;
	while (++(n[0]) < n[1])
	{
		tk[*n] = get_next_token(i);
		if (tk[*n].state == LEXER_STATE_SCOPE_UP)
			scope += tk[*n].len;
		else if (tk[*n].state == LEXER_STATE_SCOPE_DOWN)
			scope -= tk[*n].len;
		if (scope <= 0 || tk[*n].state == LEXER_STATE_MAX)
			break ;
	}
	if (update_scope(tk, i, *n + 1) != n[2])
		return (PARSER_ERROR_SYNTAX);
	return (PARSER_VALID);
}

inline uint32_t				parse_number(t_token t, double *d, uint32_t *n)
{
	char					*s;

	(void)n;
	if (t.state != LEXER_STATE_PARAMETER_NUMBER)
		return (PARSER_ERROR_SYNTAX);
	*d = ft_strtod(t.str, &s);
	if (s == t.str)
		return (PARSER_ERROR_SYNTAX);
	return (PARSER_VALID);
}
