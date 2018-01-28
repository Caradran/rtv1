/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_string_expand.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 19:58:44 by mbeilles          #+#    #+#             */
/*   Updated: 2017/09/18 19:58:48 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_t_string_expand(t_string *string)
{
	char	*tmp;

	tmp = NULL;
	if (!(tmp = ft_strnew(string->capacity * 2)))
		exit(EXIT_FAILURE);
	string->capacity *= 2;
	ft_memcpy(tmp, string->string, string->len);
	string->string[string->len] = '\0';
	free(string->string);
	string->string = tmp;
}
