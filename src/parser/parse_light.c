/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:34:05 by mbeilles          #+#    #+#             */
/*   Updated: 2018/02/23 09:15:19 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static inline t_lights		*create_light(t_lights *next, t_lgt light)
{
	static double			nblgt = 0.0;
	t_lights				*lights;
	t_lights				*tmp;

	if (!(lights = (t_lights*)malloc(sizeof(t_lights))))
		exit(EXIT_FAILURE);
	lights->lgt = light;
	lights->next = next;
	nblgt += 1;
	tmp = lights;
	while (tmp)
	{
		tmp->nblgt = nblgt;
		tmp = tmp->next;
	}
	return (lights);
}

/*
** 			light(pos(10, 0, 0), color(1, 1, 1, 1))
*/

uint32_t					parse_light(t_token t, t_token_info *i, t_env *env)
{
	static uint32_t			token_number[3] = {0, 17, 6};
	t_token					tk[32];
	uint32_t				n;
	uint32_t				ret;
	t_lgt					light;

	if (get_tokens(i, t, token_number, tk) || token_number[0] < 15)
		return (PARSER_ERROR_SYNTAX);
	print_tokens(tk, token_number[0] + 1);
	n = ~0U;
	ret = PARSER_VALID;
	while (++n < token_number[0])
	{
		if (tk[n].state == LEXER_STATE_OBJECT && ft_strnequ(tk[n].str, "pos", 3))
			ret = parse_vector(tk + n, 6, &(light.vect), &n);
		if (tk[n].state == LEXER_STATE_OBJECT && ft_strnequ(tk[n].str, "color", 5))
			ret = parse_color(tk + n, 7, &(light.col), &n);
		if (ret != PARSER_VALID)
			return (ret);
	}
	env->lights = create_light(env->lights, light);
	return (PARSER_VALID);
}
