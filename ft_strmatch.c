/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmatch.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 14:24:05 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/14 11:56:57 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strmatch(const char *str, const char *match)
{
	int len;

	len = 0;
	if (!str || !match)
		return (-1);
	while (ft_strchr(match, str[len]) != NULL && str[len] != '\0')
		len++;
	if (str[len] == '\0')
		len--;
	return (len);
}
