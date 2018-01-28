/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 09:44:35 by mbeilles          #+#    #+#             */
/*   Updated: 2017/10/25 18:46:51 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include "libft.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcast-qual"
#pragma clang diagnostic ignored "-Wgnu-binary-literal"

static inline t_double		ft_strtod_parse_special(char *str, t_double d
		, char **endptr, uint32_t *breaker)
{
	*breaker = 0;
	if (ft_strnequ(str, "NaN", 3) || ft_strnequ(str, "nan", 3))
	{
		d.s.exp = 2047U;
		d.s.mant = 0b1111111111111111111111111111111111111111111111111111;
		*breaker = 1;
		*endptr = str + 3;
		return (d);
	}
	if ((ft_strnequ(str, "inf", 3) && (*breaker = 2))
		|| (ft_strnequ(str, "infinity", 8) && (*breaker = 3)))
	{
		d.s.exp = 2047;
		d.s.mant = 0b0000000000000000000000000000000000000000000000000000;
		if (*breaker < 3)
			*endptr = str + 3;
		else
			*endptr = str + 8;
		*breaker = 1;
		return (d);
	}
	return (d);
}

static inline t_double		ft_strtod_parse_exp(char *str, t_double d
		, char **endptr)
{
	int32_t			expo;
	int32_t			sign;

	if (!(*str == 'e' || *str == 'E'))
		return (d);
	str++;
	expo = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		expo = ((int32_t)*str - '0') + (expo * 10);
		str++;
	}
	if (expo)
		d.d *= pow(10, expo);
	*endptr = str;
	return (d);
}

static inline t_double		ft_strtod_parse_frac(char *str, t_double d
		, char **endptr)
{
	uint64_t				mant;
	uint32_t				size;

	if (*str != '.')
		return (d);
	str++;
	size = 0;
	mant = 0;
	while (*str && ft_isdigit(*str))
	{
		mant = ((uint64_t)*str - '0') + (mant * 10);
		str++;
		size++;
	}
	d.d += ((double)mant) / pow(10, size);
	*endptr = str;
	return (d);
}

static inline t_double		ft_strtod_parse_int(char *str, t_double d
		, char **endptr)
{
	uint32_t			size;
	uint64_t			mant;

	mant = 0;
	size = 0;
	while (*str && ft_isdigit((int)*str) && size < 18)
	{
		mant = ((uint32_t)*str - '0') + (mant * 10);
		str++;
	}
	d.d += (double)mant;
	*endptr = str;
	return (d);
}

double						ft_strtod(const char *str, char **endptr)
{
	t_double				d;
	uint32_t				b;
	int32_t					s;

	d.d = 0;
	s = 1;
	*endptr = (char*)str;
	while (**endptr && ft_isspace(**endptr))
		(*endptr)++;
	if (**endptr == '-' && (s = -1))
		(*endptr)++;
	else if (**endptr == '+')
		(*endptr)++;
	d = ft_strtod_parse_special(*endptr, d, endptr, &b);
	if (b)
		return (d.d);
	d = ft_strtod_parse_int(*endptr, d, endptr);
	d = ft_strtod_parse_frac(*endptr, d, endptr);
	d = ft_strtod_parse_exp(*endptr, d, endptr);
	return (d.d * s);
}

#pragma clang diagnostic pop
