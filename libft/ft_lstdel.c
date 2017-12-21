/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:09:12 by esuits            #+#    #+#             */
/*   Updated: 2017/11/15 19:23:15 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*begin;

	if (alst)
	{
		begin = *alst;
		while (begin->next && *alst)
		{
			*alst = begin;
			while ((*alst)->next)
				(*alst) = (*alst)->next;
			ft_lstdelone(alst, del);
		}
		*alst = begin;
		ft_lstdelone(alst, del);
	}
}
