/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lltoa_base.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 14:16:43 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/12 19:35:05 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lltoa_base(long long value, int base)
{
	int len;
	char	*str;

	len = 0;
	if (value < 0)
	{
		value *= -1;
		len = 1;
	}
	if (value == 0)
		return (ft_strdup("0"));
	len += ft_numlen_base(value, base);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	while (value != 0)
	{
		len--;
		str[len] = (value % base) + '0';
		value /= base;
	}
	if (len == 1)
		str[0] = '-';
	return (str);
}

//You should accept base 10 with any set of chars to also be negative.
//Other bases should accept unsigned values only and return error/NULL on overflow
//Should also accept octal and hex values when receiving longs starting with 0 or 0x
//Accept min signed long long and max unsigned long long as value param. Is this possible?
//-9223372036854775808
//9223372036854775807
//At the moment not handling LLONG_MIN
//TODO: Double check other bases plus other testing