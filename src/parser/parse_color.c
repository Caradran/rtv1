/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 20:56:38 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/05 00:54:38 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

uint32_t					parse_color(t_token_info *i, t_col *col)
{
	uint64_t				c;
	t_token					t;
	char					*s;

	t = get_next_token(i);
	c = ft_strtol(t.str, &s, 10);
	if (t.str == s && !ft_isdigit(*(t.str)))
		return (PARSER_ERROR_SYNTAX);
	*col = (t_col){(double)(c & 0xff0000) / 255.0, (double)(c & 0xff00) / 255.0
		, (double)(c & 0xff00) / 255.0};
	return (PARSER_VALID);
}
