/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:49:14 by mbeilles          #+#    #+#             */
/*   Updated: 2018/01/31 12:08:34 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"



void				parse_sphere(char *sphere, t_token t, t_token_info i)
{
}

void				parse_file(char *path, t_env *env)
{
	t_token_info	i;
	t_token			t;

	i = create_info_token(path);
	while (t = get_next_token(i))
	{
		if (ft_strnequ(t.str, ))
	}

}
