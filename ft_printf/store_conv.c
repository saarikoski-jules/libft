/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_conv.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:04:08 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/10/22 10:04:06 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	store_uint(char chr, t_printf_arg **cur, va_list ap)
{
	(*cur)->arg.u = va_arg(ap, unsigned int);
	if (chr == 'u')
		(*cur)->conv = u;
	else if (chr == 'X')
		(*cur)->conv = X;
	else if (chr == 'x')
		(*cur)->conv = x;
}

void	store_int(char chr, t_printf_arg **cur, va_list ap)
{
	(*cur)->arg.i = va_arg(ap, int);
	if (chr == 'd')
		(*cur)->conv = d;
	else if (chr == 'i')
		(*cur)->conv = i;
}

void	store_char(char chr, t_printf_arg **cur, va_list ap)
{
	(*cur)->conv = c;
	if (chr == '%')
		(*cur)->arg.c = '%';
	else
		(*cur)->arg.c = va_arg(ap, int);
}

void	store_float(t_printf_arg **cur, va_list ap)
{
	(*cur)->conv = f;
	(*cur)->arg.f = va_arg(ap, double);
}

int		store_other(char chr, t_printf_arg **cur, va_list ap)
{
	char *tmp;

	if (chr == 's')
	{
		tmp = va_arg(ap, char *);
		if (tmp != NULL)
			(*cur)->arg.s = ft_strdup(tmp);
		else
			(*cur)->arg.s = ft_strdup("(null)");
		if (!(*cur)->arg.s)
			return (-1);
		(*cur)->conv = s;
	}
	else if (chr == 'p')
	{
		(*cur)->arg.p = va_arg(ap, unsigned long);
		(*cur)->conv = p;
	}
	return (1);
}
