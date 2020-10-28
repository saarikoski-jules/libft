/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_resize.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/22 16:22:25 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/10/28 16:32:40 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Resizes data array and sets amt accordingly.
** Returns 0 if bad params or allocation fails. New_amt can be 0
*/

static int	vector_resize(t_vector *v, size_t new_amt)
{
	void **data;

	if (v == NULL)
		return (0);
	data = ft_realloc(v->data, v->amt, new_amt * v->item_size);
	if (!data)
		return (0);
	v->data = data;
	v->amt = new_amt;
	return (1);
}

/*
** Adds item to the back of the data array if params are valid.
** Resizes array to fit new item. Returns 0 if allocation fails
*/

int			vector_push(t_vector *v, void *item)
{
	size_t last_slot;

	if (v->item_size < 1)
		v->item_size = sizeof(item);
	if (v == NULL || sizeof(item) != v->item_size)
		return (0);
	last_slot = v->amt;
	if (vector_resize(v, v->amt + 1) == 0)
		return (0);
	v->data[last_slot] = item;
	return (1);
}

/*
** Removes and sets to NULL the specified index, if within range.
** Else returns 0.
** Will resize memory block. Will not free element if allocated.
*/

int			vector_delete(t_vector *v, size_t index)
{
	size_t i;

	if (v == NULL || index >= v->amt)
		return (0);
	v->data[index] = NULL;
	i = index;
	while (i < v->amt - 1)
	{
		v->data[i] = v->data[i + 1];
		i++;
	}
	if (vector_resize(v, v->amt - 1) == 0)
		return (0);
	return (1);
}
