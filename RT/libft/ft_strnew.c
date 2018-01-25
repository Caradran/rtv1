/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:48:18 by esuits            #+#    #+#             */
/*   Updated: 2017/11/09 16:07:36 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	if (!(s = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = 0;
	while (i <= size)
		s[i++] = '\0';
	return (s);
}
