/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 04:03:39 by mbeilles          #+#    #+#             */
/*   Updated: 2017/10/25 18:44:47 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcast-qual"

static inline long		ft_isbase(int c, int base)
{
	if ('0' <= c && c <= '9')
	{
		if (c - '0' < base)
			return (1);
	}
	else if ('a' <= c && 'z' <= c)
	{
		if (c - 'a' < base)
			return (1);
	}
	else if ('A' <= c && 'Z' <= c)
	{
		if (c - 'A' < base)
			return (1);
	}
	return (0);
}

long					ft_strtol(const char *str, char **endptr, int base)
{
	long				l;

	if (base <= 0)
		return (0);
	l = 0;
	*endptr = (char*)str;
	while (**endptr && ft_isspace(**endptr))
		(*endptr)++;
	while (**endptr && ft_isbase(**endptr, base))
	{
		if ('0' <= **endptr && **endptr <= '9')
			l = **endptr - '0' + (l * base);
		else if ('a' <= **endptr && **endptr <= 'z')
			l = **endptr - 'a' + (l * base);
		else
			l = **endptr - 'A' + (l * base);
		(*endptr)++;
	}
	return (l);
}

#pragma clang diagnostic pop
