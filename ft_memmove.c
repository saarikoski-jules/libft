/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:23:42 by jsaariko       #+#    #+#                */
/*   Updated: 2019/10/28 18:23:42 by jsaariko      ########   odam.nl         */
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