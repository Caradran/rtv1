/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 20:57:30 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/24 22:18:09 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "rtv1.h"
#include "libft.h"

uint32_t					parse_vector(t_token *t, uint32_t token_number
											, t_vect *v, uint32_t *n)
{
	double					d[3];
	uint32_t				j;
	char					*s;

	if (!(t[1].state == LEXER_STATE_SCOPE_UP)
			|| !(t[5].state == LEXER_STATE_SCOPE_DOWN))
		return (PARSER_ERROR_SYNTAX);
	j = 1;
	while (++j < token_number - 1)
		if (t[j].state == LEXER_STATE_PARAMETER_NUMBER)
			d[j - 2] = ft_strtod(t[j].str, &s);
		else
			return (PARSER_ERROR_SYNTAX);
	*n += token_number - 1;
	*v = (t_vect){d[0], d[1], d[2]};
	return (PARSER_VALID);
}
