/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dprintf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/22 10:16:11 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/10/22 11:00:34 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dprintf(int fd, const char *str, ...)
{
	t_dprintf_arg	*head;
	va_list			ap;
	int				ret;
	t_const_args	params;

	if (str == NULL || fd < -1)
		return (-1);
	head = NULL;
	va_start(ap, str);
	if (gen_arg_list(&head, str, ap) == -1)
	{
		clear_list(&head);
		return (-1);
	}
	va_end(ap);
	params.fd = fd;
	params.str = str;
	ret = manage_print(params, &head);
	clear_list(&head);
	return (ret);
}
