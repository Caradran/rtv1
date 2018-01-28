/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 20:37:09 by mbeilles          #+#    #+#             */
/*   Updated: 2017/10/25 15:48:40 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_pow(int i, int pow)
{
	int		count;

	count = 0;
	if (i < 0)
		while (i <= -pow)
		{
			i /= pow;
			count++;
		}
	else
		while (i >= pow)
		{
			i /= pow;
			count++;
		}
	return (count);
}
