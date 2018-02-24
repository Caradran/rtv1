/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:05:13 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/24 22:13:41 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_lexer_pattern		*get_lexing_patterns(void)
{
	static t_lexer_pattern	p[21] = {
		(t_lexer_pattern){" ", 1, LEXER_STATE_SEPARATOR}
	, (t_lexer_pattern){"\n", 1, LEXER_STATE_SEPARATOR}
	, (t_lexer_pattern){"\t", 1, LEXER_STATE_SEPARATOR}
	, (t_lexer_pattern){",", 1, LEXER_STATE_SEPARATOR}
	, (t_lexer_pattern){";", 1, LEXER_STATE_SEPARATOR}
	, (t_lexer_pattern){"(", 1, LEXER_STATE_SCOPE_UP}
	, (t_lexer_pattern){")", 1, LEXER_STATE_SCOPE_DOWN}
	, (t_lexer_pattern){"0", 1, LEXER_STATE_PARAMETER_NUMBER}
	, (t_lexer_pattern){"1", 1, LEXER_STATE_PARAMETER_NUMBER}
	, (t_lexer_pattern){"2", 1, LEXER_STATE_PARAMETER_NUMBER}
	, (t_lexer_pattern){"3", 1, LEXER_STATE_PARAMETER_NUMBER}
	, (t_lexer_pattern){"4", 1, LEXER_STATE_PARAMETER_NUMBER}
	, (t_lexer_pattern){"5", 1, LEXER_STATE_PARAMETER_NUMBER}
	, (t_lexer_pattern){"6", 1, LEXER_STATE_PARAMETER_NUMBER}
	, (t_lexer_pattern){"7", 1, LEXER_STATE_PARAMETER_NUMBER}
	, (t_lexer_pattern){"8", 1, LEXER_STATE_PARAMETER_NUMBER}
	, (t_lexer_pattern){"9", 1, LEXER_STATE_PARAMETER_NUMBER}
	, (t_lexer_pattern){"-", 1, LEXER_STATE_PARAMETER_NUMBER}
	, (t_lexer_pattern){"+", 1, LEXER_STATE_PARAMETER_NUMBER}
	, (t_lexer_pattern){".", 1, LEXER_STATE_PARAMETER_NUMBER}
	, (t_lexer_pattern){"", 1, LEXER_STATE_MAX}};

	return (p);
}

t_lexer_state				get_next_lex(char c)
{
	t_lexer_pattern			*p;
	uint32_t				i;

	p = get_lexing_patterns();
	i = ~0U;
	while (++i < 21)
		if (c == *(p[i].pattern))
			return (p[i].state);
	return (LEXER_STATE_OBJECT);
}
