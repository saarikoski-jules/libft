/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ulltoa_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 10:45:04 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/13 10:52:32 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa_base(unsigned long long value, int base)
{
	int		len;
	char	*str;

	len = 0;
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
	return (str);
}