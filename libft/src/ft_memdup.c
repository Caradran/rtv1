/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:52:07 by mbeilles          #+#    #+#             */
/*   Updated: 2017/04/19 19:22:04 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memdup(void const *tab, size_t size)
{
	void	*new;

	if ((new = malloc(size)) == NULL)
		return (NULL);
	return (ft_memcpy(new, tab, size));
}
