/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:24:47 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/03 21:57:05 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;
	size_t l;

	i = 0;
	j = 0;
	l = ft_strlen(s2);
	if (n == 0)
		return (l);
	while (s1[i] != '\0')
		i++;
	if (i < n)
		l += i;
	else
		l += n;
	while (i < n - 1)
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	return (l);
}
