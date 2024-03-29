/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 09:56:26 by jsaariko      #+#    #+#                 */
/*   Updated: 2019/10/30 12:08:17 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *result;
	const char *s_copy;

	s_copy = s;
	result = NULL;
	while (*s_copy != '\0')
	{
		if (*s_copy == c)
		{
			result = s_copy;
		}
		s_copy++;
	}
	if (c == 0)
	{
		return ((char *)s_copy);
	}
	return ((char *)result);
}
