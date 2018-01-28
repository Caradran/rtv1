/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 23:13:32 by mbeilles          #+#    #+#             */
/*   Updated: 2017/04/19 23:19:09 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstiter(t_list *alst, void (*f)(t_list *elem))
{
	t_list	*tmp;

	tmp = NULL;
	while (alst)
	{
		tmp = alst->next;
		f(alst);
		alst = tmp;
	}
}
