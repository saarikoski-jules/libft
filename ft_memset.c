/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 13:36:38 by jsaariko       #+#    #+#                */
/*   Updated: 2019/10/29 13:36:56 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char *ptr_copy;

	ptr_copy = ptr;
	while (n > 0)
	{
		*ptr_copy = c;
		ptr_copy++;
		n--;
	}
	return (ptr);
}
