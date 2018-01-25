/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:15:50 by esuits            #+#    #+#             */
/*   Updated: 2017/11/12 22:04:19 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t l)
{
	unsigned int n;
	unsigned int i;
	unsigned int j;

	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (src[j])
		j++;
	if (l < i)
		return (j + l);
	n = 0;
	while (i + n < l - 1 && src[n])
	{
		dst[i + n] = src[n];
		n++;
	}
	dst[i + n] = '\0';
	return (i + j);
}
