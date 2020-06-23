/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 13:02:19 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/03/15 12:47:20 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef union		u_type
{
	long long			i;
	unsigned long long	u;
	char				c;
	char				*s;
	unsigned long long	p;
	double				f;
}					t_type;

typedef enum		e_conversion
{
	d,
	i,
	u,
	c,
	s,
	x,
	X,
	p,
	f,
}					t_conversion;

typedef enum		e_padding
{
	p_normal,
	p_zero,
	p_left,
}					t_padding;

typedef struct		s_printf_arg
{
	t_conversion			conv;
	t_type					arg;
	t_padding				pad_type;
	size_t					field_width;
	size_t					arg_width;
	ssize_t					precision;
	struct s_printf_arg		*next;
}					t_printf_arg;

typedef	enum		e_transition_code
{
	t_dash,
	t_zero,
	t_num,
	t_dot,
	t_ast,
	t_error,
	t_exit,
}					t_transition_code;

typedef char *(*t_func)(t_printf_arg **);

/*
**	PARSER
*/

void				manage_parser(t_printf_arg **arg, char *tokens, va_list ap);
t_transition_code	get_transition(char token);
t_transition_code	get_transition_code(char token);
void				store_int(char c, t_printf_arg **cur, va_list ap);
void				store_uint(char c, t_printf_arg **cur, va_list ap);
void				store_char(char c, t_printf_arg **cur, va_list ap);
void				store_float(t_printf_arg **cur, va_list ap);
int					store_other(char c, t_printf_arg **cur, va_list ap);
void				add_conv(char **final, char *conv, t_printf_arg **arg);

/*
**	EXECUTOR
*/

int					manage_print(const char *str, t_printf_arg **head);
char				*execute_arg(t_printf_arg **cur_arg);
int					gen_arg_list(t_printf_arg **head, const char *str,
									va_list ap);
char				*convert_char(t_printf_arg **arg);
char				*convert_int(t_printf_arg **arg);
char				*convert_uint(t_printf_arg **arg);
char				*convert_str(t_printf_arg **arg);
char				*convert_hex_lc(t_printf_arg **arg);
char				*convert_hex_uc(t_printf_arg **arg);
char				*convert_ptr(t_printf_arg **arg);
char				*convert_float(t_printf_arg **arg);
char				*apply_precision(t_printf_arg **arg, char *str);
char				*fill_buffer(t_printf_arg **arg);

void				clear_list(t_printf_arg **head);

#endif
