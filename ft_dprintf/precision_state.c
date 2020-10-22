/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   precision_state.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/09 22:29:40 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/10/22 10:10:57 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	prec_state(char token, t_dprintf_arg **arg, va_list ap)
{
	(void)token;
	(void)ap;
	(*arg)->precision = 0;
}
