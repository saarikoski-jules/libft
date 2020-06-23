/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transition_code.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 16:29:43 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/02/19 20:56:19 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_transition_code	get_transition(char token)
{
	if (token == '-')
		return (t_dash);
	else if (token == '0')
		return (t_zero);
	else if (token == '.')
		return (t_dot);
	else if (token <= '9' && token >= '1')
		return (t_num);
	else if (token == '*')
		return (t_ast);
	else if (token == '\0')
		return (t_exit);
	else
		return (t_error);
}
