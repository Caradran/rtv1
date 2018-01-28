/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 19:41:25 by mbeilles          #+#    #+#             */
/*   Updated: 2017/10/25 16:50:32 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	size;
	unsigned int	sign;
	char			*s;

	sign = n >= 0 ? 0 : 1;
	size = (unsigned int)ft_get_pow(n, 10) + 1 + sign;
	if (!(s = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	s[size] = 0;
	while (size--)
	{
		s[size] = n >= 0 ? '0' + n % 10 : '0' - n % 10;
		n /= 10;
	}
	if (sign)
		*s = '-';
	return (s);
}
