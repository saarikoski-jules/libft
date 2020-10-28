/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 13:27:22 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/10/28 13:15:54 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new;

	new = malloc(new_size);
	if (new == NULL)
		return (NULL);
	if (ptr == NULL)
		return (new);
	if (old_size <= new_size)
		ft_memmove(new, ptr, old_size);
	else
		ft_memmove(new, ptr, new_size);
	free(ptr);
	return (new);
}
