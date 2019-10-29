/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 13:31:01 by jsaariko       #+#    #+#                */
/*   Updated: 2019/10/29 13:31:29 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_cpy;
	unsigned char		ch;

	s_cpy = s;
	ch = (unsigned char)c;
	while (n > 0)
	{
		if (ch == *s_cpy)
		{
			return ((void *)s_cpy);
		}
		s_cpy++;
		n--;
	}
	return (NULL);
}
