/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zero_state.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:01:48 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/10/22 10:10:57 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	zero_state(char token, t_dprintf_arg **arg, va_list ap)
{
	if ((*arg)->pad_type != p_left)
		(*arg)->pad_type = p_zero;
	(void)token;
	(void)ap;
}
