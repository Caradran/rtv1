/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:03:28 by mbeilles          #+#    #+#             */
/*   Updated: 2017/10/25 18:49:09 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcast-qual"

char	*ft_strchr(const char *s, int c)
{
	const char	*tmp;

	tmp = (const char *)s;
	while (*tmp)
	{
		if (*tmp == (char)c)
			return ((char*)tmp);
		tmp++;
	}
	if ((char)c == '\0')
		return ((char*)tmp);
	return (NULL);
}

#pragma clang diagnostic pop
