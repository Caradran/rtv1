/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 21:21:35 by mbeilles          #+#    #+#             */
/*   Updated: 2017/10/25 18:12:00 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

static void			*dealloc_tab(char **tab, size_t index)
{
	while (index + 1 > 0)
	{
		free(tab[index - 1]);
		index--;
	}
	free(tab);
	return (NULL);
}

static unsigned int	get_words(const char *str, char c)
{
	unsigned int		i;
	unsigned int		word;
	unsigned int		in_word;

	i = 0;
	word = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			if (!in_word)
			{
				in_word = 1;
				word++;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (word);
}

static char			*cut_word(const char *str, char c)
{
	unsigned int		i;
	unsigned int		j;
	char				*str_r;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	j = i;
	i = 0;
	if ((str_r = (char*)malloc(sizeof(char) * j + 1)) == NULL)
		return (NULL);
	while (i < j)
	{
		str_r[i] = str[i];
		i++;
	}
	str_r[i] = '\0';
	return (str_r);
}

static char			*get_word(const char *str, unsigned int w, char c)
{
	unsigned int		i;
	unsigned int		word;
	unsigned int		in_word;

	i = 0;
	word = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			if (!in_word)
			{
				in_word = 1;
				word++;
				if (word == w)
					return (cut_word(str + i, c));
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (ft_strdup(str + i));
}

char				**ft_strsplit(char const *str, char c)
{
	unsigned int	i;
	unsigned int	k;
	char			*str_r_of_the_jedi;
	char			**tab;

	i = 0;
	if ((tab = (char**)malloc(sizeof(tab) * (get_words(str, c) + 1)))
			== NULL)
		return (NULL);
	while (i < get_words(str, c))
	{
		k = 0;
		str_r_of_the_jedi = get_word(str, i + 1, c);
		while (str_r_of_the_jedi[k])
			k++;
		if ((tab[i] = (char*)malloc(sizeof(tab[i]) * k + 1)) == NULL)
			return (dealloc_tab(tab, i));
		tab[i] = &*str_r_of_the_jedi;
		tab[i][k] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
