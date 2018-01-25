/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:40:23 by esuits            #+#    #+#             */
/*   Updated: 2017/11/12 18:16:09 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((char)c == str[i])
			return ((char*)&str[i]);
		i++;
	}
	if ((char)c == str[i])
		return ((char*)&str[i]);
	return (NULL);
}
