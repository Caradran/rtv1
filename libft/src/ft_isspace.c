/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 14:18:46 by mbeilles          #+#    #+#             */
/*   Updated: 2017/10/25 16:47:56 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	if ((unsigned char)c == '\t' ||
			(unsigned char)c == '\n' ||
			(unsigned char)c == '\v' ||
			(unsigned char)c == '\f' ||
			(unsigned char)c == '\r' ||
			(unsigned char)c == ' ')
		return (1);
	else
		return (0);
}
