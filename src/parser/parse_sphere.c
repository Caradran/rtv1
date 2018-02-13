/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 20:57:13 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/11 12:49:05 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static inline t_formes		*create_sphere(t_formes *next, t_vect t
											, t_col col, double r)
{
	t_formes				*f;

	if (!(f = (t_formes*)malloc(sizeof(t_formes))))
		exit(EXIT_FAILURE);
	f = ft_memcpy(f, &((t_formes){next, 2, (t_sph){t, col, r}
			, (t_plan){(t_vect){0, 0, 0}, 0, (t_col){0, 0, 0, 0}}})
			, sizeof(t_formes));
	return (f);
}

static inline void			get_sphere_tokens(t_token_info *i, t_token t
												, uint32_t *n, t_token *tk)
{
	*n = ~0U;
	tk[0] = t;
	while (++*n < 15)
	{
		tk[*n] = get_next_token(i);
		if (tk[*n].state == LEXER_STATE_MAX && *n < 14)
			return ;
	}
}

static inline int32_t		update_scope(t_token t, int32_t *scope)
{
	if (t.state == LEXER_STATE_SCOPE_UP)
	{
		*scope += t.len;
		return (1);
	}
	if (t.state == LEXER_STATE_SCOPE_DOWN)
	{
		*scope -= t.len;
		return (1);
	}
	return (0);
}

/*
** 			sphere ( vector ( 0 0 0 ) 0.8 color ( 255 255 255 ) ) 
*/

uint32_t					parse_sphere(t_token t, t_token_info *i, t_env *env)
{
	t_token					tk[16];
	uint32_t				token_number;
	uint32_t				n;
	t_vect					v;
	double					r;
	t_col					c;

	get_sphere_tokens(i, t, &token_number, tk);
	if (token_number < 14)
		return (PARSER_ERROR_SYNTAX);
	n = 0;
	while (update_scope(tk[n], &(i->scope)))
		n++;
	if (tk[n].state == LEXER_STATE_OBJECT && ft_strnequ(tk[n].str, "vector", 6)
			&& (n += parse_vector(tk[n], i, &v)))
		if (tk[n].state == LEXER_STATE_PARAMETER_NUMBER
				&& (r = ft_strtod(tk[n].str, &(tk[n].str))))
			if (n++ && tk[n].state == LEXER_STATE_OBJECT
					&& ft_strnequ(tk[n].str, "color", 5))
				if (parse_color(tk[n], i, &c)
						&& create_sphere(env->formes, v, c, r))
					return (PARSER_VALID);
	return (PARSER_ERROR_SYNTAX);
}
