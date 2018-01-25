/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:56:05 by esuits            #+#    #+#             */
/*   Updated: 2017/11/16 17:05:23 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	if (!s[0])
		return ("\0");
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	j = 0;
	while (s[j])
		j++;
	j--;
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j)
		j--;
	if (!(str = (char*)malloc(sizeof(char) * (j - i + 1) + 1)))
		return (NULL);
	k = 0;
	while (i <= j)
		str[k++] = s[i++];
	str[k] = '\0';
	return (str);
}
