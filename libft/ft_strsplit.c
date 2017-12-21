/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:19:01 by esuits            #+#    #+#             */
/*   Updated: 2017/11/11 23:49:50 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_countwords(const char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	if (c == 0)
		return (1);
	return (j);
}

static int	ft_countchar(const char *s, char c, int n)
{
	int i;
	int j;
	int nb;

	i = 0;
	j = 0;
	if (n > ft_countwords(s, c) || n <= 0)
		return (0);
	while (j < n)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			if (++j == n)
				break ;
		while (s[i] && s[i] != c)
			i++;
	}
	nb = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		nb++;
	}
	return (nb);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		nb[2];
	int		n;

	nb[0] = ft_countwords(s, c);
	j = 1;
	i = 0;
	if (!s || !(result = (char**)malloc(sizeof(char*) * nb[0] + 1)))
		return (NULL);
	while ((j <= nb[0]) && (nb[1] = ft_countchar(s, c, j)))
	{
		if (!(result[j - 1] = (char*)malloc(sizeof(char) * nb[1] + 1)))
			return (NULL);
		while (s[i] && s[i] == c)
			i++;
		if (!(n = 0) && s[i])
			j++;
		while (s[i] && s[i] != c)
			result[j - 2][n++] = s[i++];
		result[j - 2][n] = '\0';
	}
	result[j - 1] = NULL;
	return (result);
}
