/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 18:58:51 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/06 10:11:57 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen_base(long long value, long long base)
{
	int len;

	len = 0;
	if (base == 1)
		return (-1);
	while (value != 0)
	{
		value /= base;
		len++;
	}
	return (len);
}
