/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_toolkit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 22:28:58 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/23 09:11:21 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

inline void					print_tokens(t_token *t, uint32_t n)
{
	uint32_t				j;

	j = ~0U;
	while (++j < n)
		printf(HD"[Tokens %d] -%d- '%.*s'\n"C_NRM, j + 1, t[j].state, t[j].len, t[j].str);
}

inline int32_t				update_scope(t_token *t, t_token_info *i
											, uint32_t token_number)
{
	uint32_t				n;
	uint32_t				changes;

	n = ~0U;
	changes = 0;
	while (++n < token_number)
	{
		printf("TOKENS '%8.*s'", t[n].len, t[n].str);
		if (t[n].state == LEXER_STATE_SCOPE_UP)
		{
			printf(" +%d", t[n].len);
			changes += t[n].len;
			i->scope += t[n].len;
		}
		if (t[n].state == LEXER_STATE_SCOPE_DOWN)
		{
			printf(" -%d", t[n].len);
			changes += t[n].len;
			i->scope -= t[n].len;
		}
		printf("\n");
	}
	printf("%d - %d\n", changes, token_number);
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
		printf(HD"Token: '%.*s'\n"C_NRM, tk[*n].len, tk[*n].str);
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
	printf(HD"%.*s -> %f\n"C_NRM, t.len, t.str, *d);
	if (s == t.str)
		return (PARSER_ERROR_SYNTAX);
	return (PARSER_VALID);
}
