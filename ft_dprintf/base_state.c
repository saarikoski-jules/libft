/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   base_state.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:01:56 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/10/22 10:10:57 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	entry_state(char token, t_dprintf_arg **arg, va_list ap)
{
	(void)token;
	(void)(*arg);
	(void)ap;
}

void	exit_state(char token, t_dprintf_arg **arg, va_list ap)
{
	(void)token;
	(void)(*arg);
	(void)ap;
}
