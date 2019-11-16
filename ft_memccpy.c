/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 13:28:19 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/07 22:52:11 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char		uc;
	unsigned char		*s1_copy;
	const unsigned char	*s2_copy;

	s1_copy = (unsigned char *)s1;
	s2_copy = (const unsigned char *)s2;
	uc = (unsigned char)c;
	while (n > 0)
	{
		*s1_copy = *s2_copy;
		if (*s2_copy == uc)
		{
			s1_copy++;
			return (s1_copy);
		}
		s1_copy++;
		s2_copy++;
		n--;
	}
	return (NULL);
}
