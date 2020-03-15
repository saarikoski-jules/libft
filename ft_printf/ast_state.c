/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ast_state.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 21:14:00 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/05 18:17:06 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ast_state(char token, t_printf_arg **arg, va_list ap)
{
	int ast;

	ast = va_arg(ap, int);
	if (ast < 0)
	{
		(*arg)->pad_type = p_left;
		ast *= -1;
	}
	(*arg)->field_width = ast;
	(void)token;
}

void	prec_ast_state(char token, t_printf_arg **arg, va_list ap)
{
	int ast;

	ast = va_arg(ap, int);
	if (ast >= -1)
		(*arg)->precision = ast;
	else
		(*arg)->precision = -1;
	(void)token;
}
