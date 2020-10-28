/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_get.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 17:40:31 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/10/28 18:41:02 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns null if can't find item. Else returns pointer to index
*/

void		*vector_get(t_vector *v, size_t index)
{
	if (v == NULL)
		return (NULL);
	if (index < v->amt)
		return (v->data[index]);
	return (NULL);
}
