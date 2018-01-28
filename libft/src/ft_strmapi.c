/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 19:06:26 by mbeilles          #+#    #+#             */
/*   Updated: 2017/10/25 17:50:43 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	i;
	unsigned int	j;

	if ((map = ft_strdup(s)) == NULL)
		return (NULL);
	j = (unsigned int)ft_strlen(map);
	i = 0;
	while (i < j)
	{
		map[i] = f(i, map[i]);
		i++;
	}
	return (map);
}
