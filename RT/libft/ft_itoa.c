/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:36:49 by esuits            #+#    #+#             */
/*   Updated: 2017/11/14 12:29:03 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int n)
{
	int		sign;
	int		nb;
	int		len;
	char	*res;

	sign = 1;
	len = 1;
	if (n < 0)
		sign = -(len++);
	nb = n;
	while (nb /= 10)
		len++;
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	nb = n;
	while (len--)
	{
		res[len] = sign * (n % 10) + 48;
		n /= 10;
	}
	if (sign == -1 && nb != 0)
		res[0] = '-';
	return (res);
}
