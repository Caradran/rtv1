/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:33:36 by esuits            #+#    #+#             */
/*   Updated: 2017/11/12 18:07:46 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newl;
	t_list	*begin;
	t_list	*beginnl;

	if (!lst || !f)
		return (NULL);
	begin = lst;
	newl = f(lst);
	beginnl = newl;
	while (lst && lst->next)
	{
		if (!newl)
			return (NULL);
		lst = lst->next;
		newl->next = f(lst);
		newl = newl->next;
	}
	return (beginnl);
}
