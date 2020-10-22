/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_int.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 14:53:15 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/10/22 10:10:57 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

char	*convert_int(t_dprintf_arg **arg)
{
	char *prec_buffer;
	char *num;

	if ((*arg)->arg.i == 0 && (*arg)->precision == 0)
		num = ft_strdup("");
	else
		num = ft_lltoa_base((long long)(*arg)->arg.i, 10);
	if (!num)
		return (NULL);
	prec_buffer = apply_precision(arg, num);
	if (!prec_buffer)
	{
		free(num);
		return (NULL);
	}
	if ((*arg)->arg.i < 0)
		ft_memcpy(prec_buffer + ft_strlen(prec_buffer) - ft_strlen(num) + 1,
					num + 1, ft_strlen(num) - 1);
	else
		ft_memcpy(prec_buffer + ft_strlen(prec_buffer) - ft_strlen(num),
					num, ft_strlen(num));
	free(num);
	return (prec_buffer);
}

char	*convert_uint(t_dprintf_arg **arg)
{
	char *prec_buffer;
	char *num;

	if ((*arg)->arg.u == 0 && (*arg)->precision == 0)
		num = ft_strdup("");
	else
		num = ft_ulltoa_base((long long)(*arg)->arg.u, 10);
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
	return (prec_buffer);
}
