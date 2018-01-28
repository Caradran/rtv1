/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 05:35:27 by mbeilles          #+#    #+#             */
/*   Updated: 2017/04/14 18:29:55 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int i, int fd)
{
	if (i == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putchar_fd('1', fd);
		ft_putchar_fd('4', fd);
		ft_putchar_fd('7', fd);
		ft_putchar_fd('4', fd);
		ft_putchar_fd('8', fd);
		ft_putchar_fd('3', fd);
		ft_putchar_fd('6', fd);
		ft_putchar_fd('4', fd);
		ft_putchar_fd('8', fd);
		return ;
	}
	if (i < 0)
	{
		i = -i;
		ft_putchar_fd('-', fd);
	}
	if (i >= 10)
		ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd(i % 10 + '0', fd);
}
