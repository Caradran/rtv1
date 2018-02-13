/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 20:57:30 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/11 12:39:56 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "rtv1.h"
#include "libft.h"

uint32_t						parse_vector(t_token t, t_token_info *i
												, t_vect *v)
{
	double					d[3];
	uint32_t				j;
	char					*s;

	j = 0;
	if (!ft_strnequ(t.str, "vector", 6))
		return (PARSER_ERROR_SYNTAX);
	while (42)
	{
		t = get_next_token(i);
		if (t.state | (LEXER_STATE_PARAMETER_NUMBER + LEXER_STATE_SEPARATOR))
			if (t.state == LEXER_STATE_PARAMETER_NUMBER)
			{
				d[j++] = ft_strtod(t.str, &s);
				if (t.str == s && !ft_isdigit(*(t.str)))
					return (PARSER_ERROR_SYNTAX);
			}
		if (j >= 3)
		{
			*v = (t_vect){d[0], d[1], d[2]};
			return (PARSER_VALID);
		}
	}
}
