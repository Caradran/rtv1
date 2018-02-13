/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:08:41 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/11 12:40:35 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdint.h>
# include "rtv1.h"

/*
** =============================================================================
**
** 							Parser
**
** =============================================================================
** 							Lexer
** =============================================================================
*/

typedef enum				e_lexer_state
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
	int32_t					scope;
}							t_token_info;

typedef struct				s_token
{
	char					*str;
	uint32_t				len;
	t_lexer_state			state;
}							t_token;

t_token						get_next_token(t_token_info *i);

/*
** =============================================================================
** 							Parser
** =============================================================================
*/

# define PARSER_PATTERN_MAX	6
# define LEXER_NULL_TOKEN	((t_token){NULL, 0, LEXER_STATE_MAX})

typedef uint32_t			(*t_parser_func)(t_token, t_token_info*, t_env*);

typedef enum				e_parser_state
{
	PARSER_VALID = 0,
	PARSER_ERROR_SYNTAX,
	PARSER_ERROR_INIT,
	PARSER_ERROR_TOKEN
}							t_parser_state;

typedef struct				s_parser_pattern
{
	char					*str;
	uint32_t				len;
	t_parser_func			func;
}							t_parser_pattern;

t_token_info				create_info_token(char *path);

uint32_t					parse_color(t_token t, t_token_info *i, t_col *c);
uint32_t					parse_vector(t_token t, t_token_info *i, t_vect *v);

uint32_t					parse_sphere(t_token t, t_token_info *i, t_env *e);
uint32_t					parse_plane(t_token t, t_token_info *i, t_env *e);
uint32_t					parse_light(t_token t, t_token_info *i, t_env *e);
uint32_t					parse_cone(t_token t, t_token_info *i, t_env *e);
uint32_t					parse_cam(t_token t, t_token_info *i, t_env *e);
uint32_t					parse_cylinder(t_token t, t_token_info *i
		, t_env *e);

/*
** =============================================================================
**
** 							Toolkit
**
** =============================================================================
*/

typedef enum				e_toolkit_type
{
	TOOLKIT_MATCH_PATTERN = 0,
	TOOLKIT_MATCH_TOKEN_TYPE,
	TOOLKIT_MATCH_TOKEN_LEN,
	TOOLKIT_MATCH_REGEX,
	TOOLKIT_MATCH_MAX
}							t_toolkit_type;

typedef struct				s_tk_default
{
	t_toolkit_type			type;
}							t_tk_default;

typedef struct				s_tk_pattern_match
{
	t_toolkit_type			type;
	char					*str;
	uint32_t				len;
}							t_tk_pattern_match;

typedef struct				s_tk_type_match
{
	t_toolkit_type			type;
	char					*str;
	uint32_t				len;
}							t_tk_type_match;

typedef struct				s_tk_len_match
{
	t_toolkit_type			type;
	uint32_t				len;
}							t_tk_len_match;

typedef struct				s_tk_regex_match
{
	t_toolkit_type			type;
	char					*str;
	uint32_t				len;
}							t_tk_regex_match;

typedef union				u_toolkit_syntax
{
	t_tk_default			std;
	t_tk_pattern_match		pattern;
	t_tk_type_match			token_type;
	t_tk_len_match			token_len;
	t_tk_regex_match		regex; //Disabled
}							t_toolkit_syntax;

#endif
