/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_str.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 18:22:06 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/10/22 10:10:57 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

char	*convert_str(t_dprintf_arg **arg)
{
	char *new;

	if ((*arg)->precision != -1 &&
		(*arg)->precision < (ssize_t)ft_strlen((*arg)->arg.s))
	{
		new = (char *)ft_calloc((*arg)->precision + 1, sizeof(char));
		if (!new)
			return (NULL);
		ft_strlcpy(new, (*arg)->arg.s, (*arg)->precision + 1);
	}
	else
	{
		new = ft_strdup((*arg)->arg.s);
	}
	if (!new)
		return (NULL);
	(*arg)->arg_width = ft_strlen(new);
	return (new);
}
