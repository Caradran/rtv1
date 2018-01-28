/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 20:50:17 by mbeilles          #+#    #+#             */
/*   Updated: 2017/10/25 18:24:41 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;

	start = 0;
	while (ft_isset(s[start], " \n\t"))
		start++;
	if (s[start] == '\0')
		return (ft_strdup(s + start));
	end = ft_strlen(s) - 1;
	while (end > 0 && ft_isset(s[end], " \n\t"))
		end--;
	return (ft_strsub(s, (unsigned int)start, end - start + 1));
}
