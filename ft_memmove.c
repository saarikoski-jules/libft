/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 13:35:33 by jsaariko       #+#    #+#                */
/*   Updated: 2019/10/29 13:35:49 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char *temp;

	temp = (unsigned char *)malloc(n);
	memcpy(temp, s2, n);
	memcpy(s1, temp, n);
	free(temp);
	return (s1);
}
