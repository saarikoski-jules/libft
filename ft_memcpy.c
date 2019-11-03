/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 13:33:47 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/03 14:48:01 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//original memcpy crashes when only one (either) of the params is null. When both params are null it returns null

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
//	THESE ARE THE SAME THING!!!
	unsigned char		*s1_copy;
	const unsigned char	*s2_copy;

	s1_copy = s1;
	s2_copy = s2;
	if (s1 == NULL && s2 == NULL)
		return (s1);
	while (n > 0)
	{
		*s1_copy = *s2_copy;
		s1_copy++;
		s2_copy++;
		n--;
	}
	return (s1);
}

/*
void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*s1_copy;
	const char	*s2_copy;
	size_t	i;

	s1_copy = s1;
	s2_copy = s2;
	i = 0;
	while(i < n)
	{
		s1_copy[i] = s2_copy[i];
		i++;
	}
	return (s1);
}
*/
