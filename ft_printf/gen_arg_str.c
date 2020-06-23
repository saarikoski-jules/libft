/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gen_arg_str.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/16 15:27:26 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/03/09 18:47:05 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_conv(char **final, char *conv, t_printf_arg **arg)
{
	size_t final_len;
	size_t conv_len;

	final_len = ft_strlen(*final);
	conv_len = ft_strlen(conv);
	if ((*arg)->conv == c && (*arg)->arg.c == 0)
		conv_len++;
	if ((*arg)->pad_type == p_left)
		ft_memcpy(*final, conv, conv_len);
	else
		ft_memcpy(*final + final_len - conv_len, conv, conv_len);
	if ((*arg)->arg.i < 0 &&
		((*arg)->conv == i || (*arg)->conv == d || (*arg)->conv == f))
		ft_memcpy(ft_strchr(*final, '0'), "-", 1);
	if ((*arg)->conv == p)
	{
		if ((*arg)->pad_type == p_normal)
			ft_memcpy(*final + final_len - conv_len, "0x", 2 * sizeof(char));
		else
			ft_memcpy(*final, "0x", 2 * sizeof(char));
	}
}
