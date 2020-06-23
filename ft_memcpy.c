/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 13:33:47 by jsaariko      #+#    #+#                 */
/*   Updated: 2019/11/06 10:11:22 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
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
