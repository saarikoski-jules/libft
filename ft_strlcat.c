/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:24:47 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/14 12:05:10 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t len;
	size_t new;

	len = ft_strlen(s1);
	if (len > n)
		return (ft_strlen(s2) + n);
	new = ft_strlcpy(&s1[len], s2, n - len);
	return (len + new);
}
