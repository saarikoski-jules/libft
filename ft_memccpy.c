/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:23:08 by jsaariko       #+#    #+#                */
/*   Updated: 2019/10/28 18:23:08 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{	
	unsigned char		*s1_copy;
	const unsigned char	*s2_copy;

	s1_copy = s1;
	s2_copy = s2;
	while(n > 0)
	{
		*s1_copy = *s2_copy;
		if (*s2_copy == c)
		{
			return (s1_copy++);	
		}
		s1_copy++;
		s2_copy++;
		n--;
	}
	return (NULL);
}