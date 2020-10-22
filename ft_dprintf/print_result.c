/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_result.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 12:05:50 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/10/22 10:55:04 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include <unistd.h>

int	print_conv(int fd, t_dprintf_arg **cur)
{
	char	*arg_str;
	int		ret;

	arg_str = execute_arg(cur);
	if (arg_str == NULL)
		return (-1);
	ret = write(fd, arg_str, (*cur)->field_width);
	free(arg_str);
	return (ret);
}

int	print_section(t_const_args params, t_dprintf_arg **cur_arg, int *i, int *prev)
{
	int ret;
	int cur_ret;

	ret = 0;
	if (params.str[*i] == '%')
	{
		cur_ret = write(params.fd, params.str + *prev, *i - *prev);
		if (cur_ret == -1)
			return (-1);
		ret += cur_ret;
		if (params.str[(*i) + 1] != '\0')
			*i += ft_strmatch(params.str + *i + 1, "0123456789-*.") + 2;
		*prev = *i;
		if (ft_strchr("cspdiuxXf%", params.str[*i - 1]) != NULL)
		{
			cur_ret = print_conv(params.fd, cur_arg);
			if (cur_ret == -1)
				return (-1);
			ret += cur_ret;
			*cur_arg = (*cur_arg)->next;
		}
	}
	else
		(*i)++;
	return (ret);
}

int	manage_print(t_const_args params, t_dprintf_arg **head)
{
	t_dprintf_arg	*cur_arg;
	int				i;
	int				prev;
	int				ret;
	int				cur_ret;

	cur_arg = *head;
	i = 0;
	prev = 0;
	ret = 0;
	while (params.str[i] != '\0')
	{
		cur_ret = print_section(params, &cur_arg, &i, &prev);
		if (cur_ret == -1)
			return (-1);
		ret += cur_ret;
	}
	cur_ret = write(params.fd, params.str + prev, i - prev);
	if (cur_ret == -1)
		return (-1);
	ret += cur_ret;
	return (ret);
}
