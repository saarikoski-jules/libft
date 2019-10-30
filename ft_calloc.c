/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 19:34:06 by jsaariko       #+#    #+#                */
/*   Updated: 2019/10/30 11:02:16 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//PLEASE DOUBLE CHECK

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *ptr;

	ptr = malloc(count * size);
	//check if malloc is succcessfull, if not, return null
	ft_memset(ptr, 0, count);
	return (ptr);
}
