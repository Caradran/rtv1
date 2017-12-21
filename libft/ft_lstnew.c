/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:30:25 by esuits            #+#    #+#             */
/*   Updated: 2017/11/12 16:08:43 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nlist;

	if (!(nlist = malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		nlist->content = NULL;
		nlist->content_size = 0;
		nlist->next = NULL;
		return (nlist);
	}
	if (!(nlist->content = malloc(content_size)))
		return (NULL);
	ft_memcpy(nlist->content, content, content_size);
	nlist->content_size = content_size;
	nlist->next = NULL;
	return (nlist);
}
