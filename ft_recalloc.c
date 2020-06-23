/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_recalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 12:10:50 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/02/11 16:03:18 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_recalloc(void *ptr, size_t size)
{
	void	*new;

	new = ft_calloc(size, 1);
	if (ptr == NULL)
		return (new);
	else
		ft_memmove(new, ptr, size - 1);
	free(ptr);
	return (new);
}
