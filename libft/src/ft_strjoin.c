/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 20:38:17 by mbeilles          #+#    #+#             */
/*   Updated: 2017/04/13 20:49:59 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;

	if ((tab = (char*)malloc(sizeof(tab) *
			(ft_strlen(s1) + ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	ft_strcpy(tab, s1);
	ft_strcat(tab, s2);
	return (tab);
}
