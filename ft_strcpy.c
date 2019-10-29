/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:24:36 by jsaariko       #+#    #+#                */
/*   Updated: 2019/10/28 18:24:36 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *s1, const char *s2, size_t n)
{
	char	*str;

	str = ft_memmove(s1, s2, n-1);
	str[n] = '\0';
	return (n);
}