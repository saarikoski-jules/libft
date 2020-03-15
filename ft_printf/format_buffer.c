/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_buffer.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 14:52:06 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/09 18:46:05 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_actual_prec(t_printf_arg **arg, char *num_str)
{
	ssize_t	len;
	int		base;
	int		prec;

	len = ft_strlen(num_str);
	if (num_str[0] == '-')
		len--;
	if ((*arg)->conv == p || (*arg)->conv == x || (*arg)->conv == X)
		base = 16;
	else
		base = 10;
	if ((*arg)->arg.i == 0 && (*arg)->precision == 0)
		prec = 0;
	else if ((*arg)->arg.i == 0 && (*arg)->precision == -1)
		prec = 1;
	else
	{
		if (len > (*arg)->precision)
			prec = len;
		else
			prec = (*arg)->precision;
	}
	if (((*arg)->conv == i || (*arg)->conv == d) && (*arg)->arg.i < 0)
		prec++;
	return (prec);
}

char			*apply_precision(t_printf_arg **arg, char *num_str)
{
	char	*new;
	int		prec;

	prec = get_actual_prec(arg, num_str);
	(*arg)->arg_width = prec;
	new = (char *)ft_calloc(prec + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_memset(new, '0', prec);
	return (new);
}

char			*fill_buffer(t_printf_arg **arg)
{
	char	*new;
	size_t	len;
	char	padding;

	new = NULL;
	len = (*arg)->arg_width;
	if ((*arg)->pad_type == p_zero)
		padding = '0';
	else
		padding = ' ';
	if (((*arg)->conv != s && (*arg)->conv != c && (*arg)->conv != f)
		&& (*arg)->precision != -1)
		padding = ' ';
	if ((*arg)->field_width < len)
		(*arg)->field_width = len;
	new = (char *)ft_calloc((*arg)->field_width + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_memset(new, padding, (*arg)->field_width);
	return (new);
}
