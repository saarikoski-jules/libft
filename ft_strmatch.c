/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmatch.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 14:24:05 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/06 10:12:32 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strmatch(const char *str, const char *match)
{
	int len;

	len = 0;
	if (!str || !match)
		return (-1);
	while (ft_strchr(match, str[len]) != NULL)
		len++;
	return (len);
}