/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 10:53:19 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/03 21:10:47 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> //REMOVE
static int	compare(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s2[i] != '\0')
	{
		if (s2[i] == s1[i])
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	const char *s1_copy;
	const char *s2_copy;

	s1_copy = s1;
	s2_copy = s2;
	if (s2_copy[0] == '\0')
	{
		return ((char *)s1_copy);
	}
	if (n < ft_strlen(s2))
		return (NULL);
	while (*s1_copy != '\0' && (n - (ft_strlen(s2) - 1)) > 0)
	{
		if (*s1_copy == s2[0])
		{
			if (compare(s1_copy, s2_copy))
			{
				return ((char *)s1_copy);
			}
		}
		s1_copy++;
		n--;
	}
	return (NULL);
}
