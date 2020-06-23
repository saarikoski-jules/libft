/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fsm.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 09:43:20 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/03/06 14:54:41 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FSM_H
# define FSM_H
# include "ft_printf.h"

/*
**	STATES
*/

void			entry_state(char token, t_printf_arg **arg, va_list ap);
void			dash_state(char token, t_printf_arg **arg, va_list ap);
void			zero_state(char token, t_printf_arg **arg, va_list ap);
void			num_state(char token, t_printf_arg **arg, va_list ap);
void			num_repeat_state(char token, t_printf_arg **arg, va_list ap);
void			prec_state(char token, t_printf_arg **arg, va_list ap);
void			prec_num_state(char token, t_printf_arg **arg, va_list ap);
void			prec_num_repeat_state(char token, t_printf_arg **arg,
										va_list ap);
void			ast_state(char token, t_printf_arg **arg, va_list ap);
void			prec_ast_state(char token, t_printf_arg **arg, va_list ap);
void			error_state(char token, t_printf_arg **arg, va_list ap);
void			exit_state(char token, t_printf_arg **arg, va_list ap);

/*
**	TRANSITION TABLE
*/

typedef struct	s_transition_obj
{
	void				(*orig_state)(char, t_printf_arg **, va_list);
	t_transition_code	transition;
	void				(*next_state)(char, t_printf_arg **, va_list);
}				t_transition_obj;

t_transition_obj const g_transition_table[] =
{
	{entry_state, t_dash, dash_state},
	{entry_state, t_zero, zero_state},
	{entry_state, t_num, num_state},
	{entry_state, t_ast, ast_state},
	{entry_state, t_dot, prec_state},
	{entry_state, t_error, error_state},
	{entry_state, t_exit, exit_state},

	{dash_state, t_dash, dash_state},
	{dash_state, t_zero, dash_state},
	{dash_state, t_num, num_state},
	{dash_state, t_ast, ast_state},
	{dash_state, t_dot, prec_state},
	{dash_state, t_error, error_state},
	{dash_state, t_exit, exit_state},

	{zero_state, t_dash, dash_state},
	{zero_state, t_zero, zero_state},
	{zero_state, t_num, num_state},
	{zero_state, t_ast, ast_state},
	{zero_state, t_dot, prec_state},
	{zero_state, t_error, error_state},
	{zero_state, t_exit, exit_state},

	{num_state, t_dash, dash_state},
	{num_state, t_zero, num_repeat_state},
	{num_state, t_num, num_repeat_state},
	{num_state, t_ast, ast_state},
	{num_state, t_dot, prec_state},
	{num_state, t_error, error_state},
	{num_state, t_exit, exit_state},

	{num_repeat_state, t_dash, dash_state},
	{num_repeat_state, t_zero, num_repeat_state},
	{num_repeat_state, t_num, num_repeat_state},
	{num_repeat_state, t_ast, ast_state},
	{num_repeat_state, t_dot, prec_state},
	{num_repeat_state, t_error, error_state},
	{num_repeat_state, t_exit, exit_state},

	{ast_state, t_dash, dash_state},
	{ast_state, t_zero, zero_state},
	{ast_state, t_num, num_state},
	{ast_state, t_ast, ast_state},
	{ast_state, t_dot, prec_state},
	{ast_state, t_error, error_state},
	{ast_state, t_exit, exit_state},

	{prec_ast_state, t_dash, dash_state},
	{prec_ast_state, t_zero, zero_state},
	{prec_ast_state, t_num, num_state},
	{prec_ast_state, t_ast, ast_state},
	{prec_ast_state, t_dot, prec_state},
	{prec_ast_state, t_error, error_state},
	{prec_ast_state, t_exit, exit_state},

	{prec_state, t_dash, dash_state},
	{prec_state, t_zero, prec_num_state},
	{prec_state, t_num, prec_num_state},
	{prec_state, t_ast, prec_ast_state},
	{prec_state, t_dot, prec_state},
	{prec_state, t_error, error_state},
	{prec_state, t_exit, exit_state},

	{prec_num_state, t_dash, dash_state},
	{prec_num_state, t_zero, prec_num_repeat_state},
	{prec_num_state, t_num, prec_num_repeat_state},
	{prec_num_state, t_ast, prec_ast_state},
	{prec_num_state, t_dot, prec_state},
	{prec_num_state, t_error, error_state},
	{prec_num_state, t_exit, exit_state},

	{prec_num_repeat_state, t_dash, dash_state},
	{prec_num_repeat_state, t_zero, prec_num_repeat_state},
	{prec_num_repeat_state, t_num, prec_num_repeat_state},
	{prec_num_repeat_state, t_ast, prec_ast_state},
	{prec_num_repeat_state, t_dot, prec_state},
	{prec_num_repeat_state, t_error, error_state},
	{prec_num_repeat_state, t_exit, exit_state},

	{error_state, t_dash, dash_state},
	{error_state, t_zero, zero_state},
	{error_state, t_num, num_state},
	{error_state, t_ast, ast_state},
	{error_state, t_dot, prec_state},
	{error_state, t_error, error_state},
	{error_state, t_exit, exit_state},
};

#endif
