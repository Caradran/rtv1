/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 20:57:13 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/06 13:04:16 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_formes				*create_sphere(t_formes *next, t_vect t
											, t_col col, double r)
{
	t_formes				*f;

	if (!(f = (t_formes*)malloc(sizeof(t_formes))))
		exit(EXIT_FAILURE);
	f = ft_memcpy(f, &((t_formes){next, 2,(t_sph){t, col, r}
			,(t_plan){(t_vect){0, 0, 0}, 0, (t_col){0, 0, 0, 0}}})
			, sizeof(t_formes));
	return (f);
}

uint32_t						parse_sphere(t_token t, t_token_info *i, t_env *env)
{
	/*t_formes					f;*/
	/*t_vect						v;*/
	/*t_col						c;*/
	/*double						r;*/

	/*while((t = get_next_token(i)).state == LEXER_STATE_SEPARATOR)*/
		/*(void)42;*/
	/*if (t.state != LEXER_STATE_SCOPE_UP)*/
		/*return (PARSER_ERROR_SYNTAX);*/
	/*while((t = get_next_token(i)).state == LEXER_STATE_SEPARATOR)*/
		/*(void)42;*/
	/*if (!(parse_vector(i, &(f.sph.ctr))) || !(parse_color(i, &f.sph.col)))*/
		/*return (PARSER_ERROR_SYNTAX);*/
	/*while((t = get_next_token(i)).state == LEXER_STATE_SEPARATOR)*/
		/*(void)42;*/
	/*if (t.state != LEXER_STATE_SCOPE_DOWN && !(parse_vector(i, &v))*/
			/*&& !(parse_color(i, &c)))*/
		/*return (PARSER_ERROR_SYNTAX);*/
	/*env->formes = create_sphere(env->formes, v, c*/
			/*, ft_strtod(get_next_token(i).str, NULL));*/
	return (PARSER_VALID);
}
