/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_ptr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 17:22:11 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/06 09:32:03 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_ptr(t_printf_arg **arg)
{
	char *prec_buffer;
	char *num;

	if ((*arg)->arg.p == 0 && (*arg)->precision == 0)
		num = ft_strdup("");
	else
		num = ft_ulltoa_base((*arg)->arg.p, 16);
	if (!num)
		return (NULL);
	prec_buffer = apply_precision(arg, num);
	if (!prec_buffer)
	{
		free(num);
		return (NULL);
	}
	ft_memcpy(prec_buffer + ft_strlen(prec_buffer) - ft_strlen(num), num,
				ft_strlen(num));
	free(num);
	num = ft_strjoin("00", prec_buffer);
	(*arg)->arg_width += 2;
	free(prec_buffer);
	if (!num)
		return (NULL);
	ft_tolowerstr(&num);
	return (num);
}
