/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:08:41 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/31 11:49:40 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdint.h>

/*
** =============================================================================
**
** 							Parser
**
** =============================================================================
** 							Lexer
** =============================================================================
*/

typedef enum				s_lexel_state
{
	LEXER_STATE_SEPARATOR = 0,
	LEXER_STATE_PARAMETER_NUMBER,
	LEXER_STATE_PARAMETER_STRING,
	LEXER_STATE_SCOPE_UP,
	LEXER_STATE_SCOPE_DOWN,
	LEXER_STATE_OBJECT,
	LEXER_STATE_MAX
}							t_lexer_state;

typedef struct				s_lexer_pattern
{
	char					*pattern;
	uint32_t				len;
	t_lexer_state			state;
}							t_lexer_pattern;

t_lexer_state				get_next_lex(char c);

/*
** =============================================================================
** 							Tokenizer
** =============================================================================
*/

typedef struct				s_token_info
{
	char					*buffer;
	uint32_t				len;
	uint32_t				index;
	t_lexer_state			last_state;
}							t_token_info;

typedef struct				s_token
{
	char					*str;
	uint32_t				len;
	t_lexer_state			state;
}							t_token;

/*
** =============================================================================
** 							Parser
** =============================================================================
*/

#endif
