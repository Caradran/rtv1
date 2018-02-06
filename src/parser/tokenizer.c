/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:29:31 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/06 13:11:08 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token_info			create_info_token(char *path)
{
	char				*str;

	str = ft_get_file_content(path);
	return ((t_token_info){str, ft_strlen(str), 0, LEXER_STATE_OBJECT});
}

static t_token			create_token(char *str, uint32_t len, t_lexer_state st)
{
	return ((t_token){str, len, st});
}

t_token					get_next_token(t_token_info *i)
{
	t_lexer_state		state;
	t_lexer_state		swap;
	uint32_t			len;

	if (i->index >= i->len - 1)
		return (LEXER_NULL_TOKEN);
	len = 1;
	state = get_next_lex(i->buffer[i->index]);
	while ((swap = get_next_lex(i->buffer[i->index + len])) == state)
		len++;
	i->index += len;
	i->last_state = state;
	return (create_token(i->buffer + i->index, len + 1, swap));
}
