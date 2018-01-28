/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 11:27:37 by mbeilles          #+#    #+#             */
/*   Updated: 2017/06/30 11:00:35 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

char		*ft_strndup(const char *str, size_t n)
{
	char		*s;

	if (!(s = (char *)malloc(n)))
		return (NULL);
	return (ft_strncpy(s, str, n));
}
