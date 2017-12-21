/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:58:16 by esuits            #+#    #+#             */
/*   Updated: 2017/11/12 18:10:43 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*tmpbis;
	size_t			i;

	tmp = (unsigned char*)dst;
	tmpbis = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		tmp[i] = tmpbis[i];
		i++;
	}
	return (dst);
}
