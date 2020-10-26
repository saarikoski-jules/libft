/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_search.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 17:41:10 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/10/26 17:44:12 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns index of first matching vector
** or -1 if not found or invalid params. Item can be NULL.
*/

int			vector_search(t_vector *v, int (*cmp)(), void *item)
{
	size_t i;

	i = 0;
	if (v == NULL || cmp == NULL)
		return (-1);
	while (i < v->amt)
	{
		if (cmp(v->data[i], item) == 0)
			return (i);
		i++;
	}
	return (-1);
}
