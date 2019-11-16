/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 13:35:33 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/07 18:27:27 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char		*s1_copy;
	const unsigned char	*s2_copy;
	size_t				i;

	s1_copy = s1;
	s2_copy = s2;
	if (s1 == NULL && s2 == NULL)
		return (s1_copy);
	if (s1_copy < s2_copy && n != 0)
		ft_memcpy(s1, s2, n);
	else
	{
		i = n;
		while (i > 0)
		{
			s1_copy[i - 1] = s2_copy[i - 1];
			i--;
		}
	}
	return (s1_copy);
}
