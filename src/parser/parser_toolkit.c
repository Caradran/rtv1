/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_toolkit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 22:28:58 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/22 22:29:48 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

inline int32_t				update_scope(t_token *t, t_token_info *i
											, uint32_t token_number)
{
	uint32_t				n;
	uint32_t				changes;

	n = ~0U;
	changes = 0;
	while (++n < token_number)
	{
		if (t[n].state == LEXER_STATE_SCOPE_UP)
		{
			changes++;
			*scope += t.len;
		}
		if (t[n].state == LEXER_STATE_SCOPE_DOWN)
		{
			changes++;
			*scope -= t.len;
		}
	}
	return (changes);
}
