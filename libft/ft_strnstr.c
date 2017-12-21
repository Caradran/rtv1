/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:55:32 by esuits            #+#    #+#             */
/*   Updated: 2017/11/07 17:39:47 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t c;
	size_t i;
	size_t j;

	i = 0;
	c = 0;
	j = 0;
	while (to_find[c] != '\0')
		c++;
	if (c == 0)
		return ((char*)str);
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j] && j + i < n)
		{
			if (j == c - 1)
				return ((char*)&(str[i]));
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
