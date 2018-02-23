/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 20:56:38 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/23 09:11:28 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

uint32_t					parse_color(t_token *t, uint32_t token_number
										, t_col *col, uint32_t *n)
{
	double					d[4];
	uint32_t				j;
	char					*s;

	printf(HD"Parsing color\n"C_NRM);
	if (!(t[1].state == LEXER_STATE_SCOPE_UP)
			|| !(t[6].state == LEXER_STATE_SCOPE_DOWN))
		return (PARSER_ERROR_SYNTAX);
	j = 1;
	while (++j < token_number - 1)
	{
		printf(HD"Color [%i]: \'%.*s\'\n"C_NRM, j - 2, t[j].len, t[j].str);
		if (t[j].state == LEXER_STATE_PARAMETER_NUMBER)
			d[j - 2] = ft_strtod(t[j].str, &s);
		else
			return (PARSER_ERROR_SYNTAX);
	}
	*n += token_number - 1;
	*col = (t_col){d[0], d[1], d[2], d[3]};
	printf(HD"Done.\n"C_NRM);
	return (PARSER_VALID);
}
