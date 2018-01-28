/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 23:22:02 by mbeilles          #+#    #+#             */
/*   Updated: 2017/10/25 18:49:21 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcast-qual"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*tmp;

	i = 0;
	tmp = (const unsigned char*)s;
	while (i < n)
	{
		if ((unsigned char)c == tmp[i])
			return ((void*)(tmp + i));
		++i;
	}
	return (NULL);
}

#pragma clang diagnostic pop
