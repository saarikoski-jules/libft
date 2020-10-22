/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   num_state.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:01:38 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/10/22 10:10:57 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	num_state(char token, t_dprintf_arg **arg, va_list ap)
{
	(*arg)->field_width = (token - 48);
	(void)ap;
}

void	num_repeat_state(char token, t_dprintf_arg **arg, va_list ap)
{
	(*arg)->field_width *= 10;
	(*arg)->field_width += (token - 48);
	(void)ap;
}

void	prec_num_state(char token, t_dprintf_arg **arg, va_list ap)
{
	(*arg)->precision = (token - 48);
	(void)ap;
}

void	prec_num_repeat_state(char token, t_dprintf_arg **arg, va_list ap)
{
	(*arg)->precision *= 10;
	(*arg)->precision += (token - 48);
	(void)ap;
}
