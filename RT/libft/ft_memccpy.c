/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:15:41 by esuits            #+#    #+#             */
/*   Updated: 2017/12/06 19:27:41 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*tmpbis;
	size_t			i;

	tmp = (unsigned char*)dst;
	tmpbis = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		tmp[i] = (unsigned char)tmpbis[i];
		if (tmpbis[i] == (unsigned char)c)
			return (&tmp[i + 1]);
		i++;
	}
	return (NULL);
}
