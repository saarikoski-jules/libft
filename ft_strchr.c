/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 09:13:28 by jsaariko       #+#    #+#                */
/*   Updated: 2019/10/31 11:57:16 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char *s_copy;

	s_copy = s;
	while (*s_copy != '\0')
	{
		if (*s_copy == c)
		{
			return ((char *)s_copy);
		}
		s_copy++;
	}
	if (c == 0)
	{
		return ((char *)s_copy);
	}
	return (NULL);
}
