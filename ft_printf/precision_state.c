/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   precision_state.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/09 22:29:40 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/03/05 18:18:11 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prec_state(char token, t_printf_arg **arg, va_list ap)
{
	(void)token;
	(void)ap;
	(*arg)->precision = 0;
}
