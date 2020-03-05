/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 18:58:51 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/05 17:02:26 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>//

int	ft_numlen_base(long long value, long long base)
{
	int len;

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
