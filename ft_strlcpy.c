/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 14:20:37 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/08 18:48:40 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t len;

	if (s2 == NULL)
		return (0);
	i = 0;
	len = ft_strlen(s2);
	if (n < 1)
		return (len);
	while (i < n - 1 && i < len)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (len);
}
