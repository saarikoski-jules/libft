/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ulltoa_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 10:45:04 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/05 17:02:36 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>//

static int ft_unumlen_base(unsigned long long value, long long base)
{
	int len;

	// printf("in unumlen: %lld, base: %llu\n", value, base);
	len = 0;
	if (base == 1)
		return (-1);
	while (value != 0)
	{
		// printf("value: %llu, base: %d\nvalue/base %llu\n", value, base, value/2);
		value /= base;
		len++;
	}
	// printf("len: %d\n", len);
	return (len);
}



char	*ft_ulltoa_base(unsigned long long value, long long base)
{
	int		len;
	char	*str;

	// printf("in ulltoa: %llu\n", value);
	len = 0;
	if (value == 0)
		return (ft_strdup("0"));
	len += ft_unumlen_base(value, base);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	while (value != 0)
	{
		len--;
		str[len] = ft_numtochar_base(value % base);
		value /= base;
	}
	return (str);
}
