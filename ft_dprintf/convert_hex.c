/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_hex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 16:29:44 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/10/22 10:10:57 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

char	*convert_hex_lc(t_dprintf_arg **arg)
{
	char *prec_buffer;
	char *num;

	if ((*arg)->arg.u == 0 && (*arg)->precision == 0)
		num = ft_strdup("");
	else
		num = ft_lltoa_base((long long)(*arg)->arg.u, 16);
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
	ft_tolowerstr(&prec_buffer);
	return (prec_buffer);
}

char	*convert_hex_uc(t_dprintf_arg **arg)
{
	char *prec_buffer;
	char *num;

	if ((*arg)->arg.u == 0 && (*arg)->precision == 0)
		num = ft_strdup("");
	else
		num = ft_lltoa_base((long long)(*arg)->arg.u, 16);
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
