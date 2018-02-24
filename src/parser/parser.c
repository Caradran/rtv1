/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:49:14 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/24 22:10:49 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_parser_pattern		*get_parser_patterns(void)
{
	static t_parser_pattern	p[PARSER_PATTERN_MAX] = {
		(t_parser_pattern){"sphere", 6, &parse_sphere}
		, (t_parser_pattern){"plane", 5, &parse_plane}
		, (t_parser_pattern){"cone", 4, &parse_cone}
		, (t_parser_pattern){"cylinder", 8, &parse_cylinder}
		, (t_parser_pattern){"cam", 3, &parse_cam}
		, (t_parser_pattern){"light", 5, &parse_light}
	};

	return (p);
}

uint32_t					parse_file(char *path, t_env *env)
{
	t_token_info			i;
	t_token					t;
	uint32_t				c;
	t_parser_pattern		*p;

	i = create_info_token(path);
	p = get_parser_patterns();
	ft_putstr(STR_INF("Parsing start\n"));
	while (42)
	{
		t = get_next_token(&i);
		if (t.state == LEXER_STATE_MAX)
			return (PARSER_VALID);
		c = ~0U;
		if (t.state == LEXER_STATE_OBJECT)
			while (++c < PARSER_PATTERN_MAX)
				if (ft_strnequ(p[c].str, t.str, p[c].len))
					if ((p[c].func(t, &i, env)))
						return (PARSER_ERROR_SYNTAX);
	}
	return (PARSER_VALID);
}
