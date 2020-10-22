/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 13:27:22 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/10/22 09:54:59 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void *new;

	new = malloc(size);
	if (ptr == NULL)
		return (new);
	ft_memmove(new, ptr, size - 1);
	free(ptr);
	return (new);
}
