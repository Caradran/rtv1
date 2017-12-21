/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 19:55:08 by esuits            #+#    #+#             */
/*   Updated: 2017/11/07 17:12:05 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int c;
	int i;
	int j;

	i = 0;
	c = 0;
	j = 0;
	while (to_find[c] != '\0')
		c++;
	if (c == 0)
		return ((char*)str);
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j])
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
