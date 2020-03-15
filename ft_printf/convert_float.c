/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_float.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 17:51:25 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/14 12:01:34 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <float.h>

char	*convert_float(t_printf_arg **arg)
{
	char *neg;
	char *final;

	if ((*arg)->precision == -1)
		(*arg)->precision = 6;
	final = ft_ftoa((*arg)->arg.f, (*arg)->precision);
	if (!final)
		return (NULL);
	(*arg)->arg_width = ft_strlen(final);
	if ((*arg)->arg.f < 0
	|| (1 / (*arg)->arg.f < -FLT_MAX && (*arg)->arg.f == 0))
	{
		neg = (char *)ft_calloc((*arg)->arg_width + 1, sizeof(char));
		if (!neg)
			return (NULL);
		ft_memset(neg, '0', 1);
		ft_memcpy(neg + 1, final + 1, (*arg)->arg_width - 1);
		free(final);
		return (neg);
	}
	return (final);
}
