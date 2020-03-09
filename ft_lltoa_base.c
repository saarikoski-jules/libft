/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lltoa_base.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 14:16:43 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/09 18:51:41 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa_base(long long value, int base)
{
	int		len;
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
		str[len] = ft_numtochar_base(value % base);
		value /= base;
	}
	if (len == 1)
		str[0] = '-';
	return (str);
}
