/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 13:27:22 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/21 21:23:55 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../libft_project/libft/libft.h"
void *ft_realloc(void *ptr, size_t size)
{
	unsigned char *new;

	new = malloc(size);
	if (ptr == NULL)
		return ((void *)new);
	ft_memmove(new, ptr);
	free(ptr);
	return ((void *)new);
}