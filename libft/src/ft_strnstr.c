/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:17:55 by mbeilles          #+#    #+#             */
/*   Updated: 2017/10/25 18:44:12 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcast-qual"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	tf_len;

	if ((tf_len = ft_strlen(to_find)) == 0)
		return ((char *)str);
	while (*str && tf_len <= len)
	{
		if ((*str == *to_find) &&
				(ft_strncmp(str, to_find, tf_len) == 0))
			return ((char*)str);
		str++;
		len--;
	}
	return (NULL);
}

#pragma clang diagnostic pop
