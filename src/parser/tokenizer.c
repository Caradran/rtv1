/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:29:31 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/31 11:49:01 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token_info			create_info_token(char *path)
{
	char				*str;

	str = ft_get_file_content(path);
	return ((t_token_info){str, ft_strlen(str), 0, LEXER_STATE_SEPARATOR});
}

static t_token			create_token(char *str, uint32_t len, t_lexer_state st)
{
	return ((t_token){str, len, st});
}

t_token					get_next_token(t_token_info i)
{
	t_lexer_state		state;
	t_lexer_state		swap;;
	uint32_t			len;

	len = 0;
	while ((state = get_next_lex(i.str[i.index++]) == i.last_state))
		len++;
	swap = state;
	state = i.last_state;
	i.last_state = swap;
	return (create_token(i.str + i.index, len, state));
}
