/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 04:53:17 by mbeilles          #+#    #+#             */
/*   Updated: 2017/10/25 17:05:40 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static inline size_t	ft_strclen(char const *s, int c)
{
	size_t		i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	return (i);
}

static inline char		*ft_strccpy(char *dest, char const *src, int c)
{
	int		i;

	i = 0;
	while (src[i] && src[i] != (char)c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char					*ft_strcdup(char const *s, int c)
{
	char	*dest;

	dest = NULL;
	if ((dest = (char*)malloc(sizeof(char) * (ft_strclen(s, c) + 1))) == NULL)
		return (NULL);
	return (ft_strccpy(dest, s, c));
}
