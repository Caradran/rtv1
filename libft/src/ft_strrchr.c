/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:09:58 by mbeilles          #+#    #+#             */
/*   Updated: 2017/10/25 18:48:00 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcast-qual"

char	*ft_strrchr(const char *s, int c)
{
	const char	*save;

	save = (const char*)NULL;
	while (*s)
	{
		if (*s == c)
			save = s;
		s++;
	}
	if (*s == c)
		save = s;
	return ((char*)save);
}

#pragma clang diagnostic pop
