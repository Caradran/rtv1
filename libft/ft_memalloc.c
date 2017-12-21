/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:00:09 by esuits            #+#    #+#             */
/*   Updated: 2017/11/12 18:10:07 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void			*s;
	char			*res;
	size_t			i;

	if (!(s = malloc(sizeof(unsigned char) * size)))
		return (NULL);
	i = 0;
	res = (char*)s;
	while (i < size)
		res[i++] = 0;
	return (s);
}
