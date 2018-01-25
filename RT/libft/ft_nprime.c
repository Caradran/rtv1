/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nprime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:17:50 by esuits            #+#    #+#             */
/*   Updated: 2017/11/12 20:15:14 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned long	*ft_nprime(unsigned long n)
{
	unsigned long	*tab;
	unsigned long	i;
	unsigned long	j;
	unsigned long	p;

	if (!(tab = (unsigned long*)malloc(sizeof(unsigned long) * (n + 1))))
		return (NULL);
	tab[1] = 0;
	i = 2;
	while (i <= n)
		tab[i++] = 1;
	p = 2;
	while (p * p <= n)
	{
		j = p * p;
		while (j <= n)
		{
			tab[j] = 0;
			j += p;
		}
		while (!tab[++p])
			i = 0;
	}
	return (tab);
}
