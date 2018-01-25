/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:18:43 by esuits            #+#    #+#             */
/*   Updated: 2017/11/12 22:21:06 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t c;

	if (!s1 || !s2)
		return (0);
	c = 0;
	while (c < n && s1[c])
	{
		if (s1[c] != s2[c])
			return (0);
		c++;
	}
	if (c < n)
		return (s1[c] == s2[c]);
	return (1);
}
