/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:40:23 by esuits            #+#    #+#             */
/*   Updated: 2017/11/07 18:11:04 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		pos;
	int		flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if ((char)c == str[i])
		{
			pos = i;
			flag = 1;
		}
		i++;
	}
	if ((char)c == str[i])
	{
		pos = i;
		flag = 1;
	}
	if (flag)
		return ((char*)&(str[pos]));
	return (NULL);
}
