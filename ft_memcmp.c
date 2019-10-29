/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:23:19 by jsaariko       #+#    #+#                */
/*   Updated: 2019/10/28 18:23:19 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *s1_cpy;
	const unsigned char *s2_cpy;

	s1_cpy = s1;
	s2_cpy = s2;

	while(n > 0)
	{
		if (*s1_cpy != *s2_cpy)
		{
			return (*s1_cpy - *s2_cpy);
		}
		s1_cpy++;
		s2_cpy++;
		n--;
	}
	return (0);
}