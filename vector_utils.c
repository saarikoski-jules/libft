/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/22 16:22:25 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/10/26 13:35:58 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** return 0 on fail and 1 on success
*/

int			vector_init(t_vector *v)
{
	if (v == NULL)
		return (0);
	v->item_size = 0;
	v->amt = 0;
	v->data = NULL;
	return (1);
}

static int	vector_resize(t_vector *v, size_t new_amt)
{
	void **data;

	data = ft_realloc(v->data, new_amt * v->item_size);
	if (!data)
		return (0);
	v->data = data;
	v->amt = new_amt;
	return (1);
}

int			vector_push(t_vector *v, void *item)
{
	size_t last_slot;

	if (v->item_size < 1)
		v->item_size = sizeof(item);
	if (v == NULL || sizeof(item) != v->item_size)
		return (0);
	last_slot = v->amt;
	vector_resize(v, v->amt + 1);
	v->data[last_slot] = item;
	return (1);
}

void		*vector_get(t_vector *v, size_t index)
{
	if (index >= 0 && index < v->amt)
		return (v->data[index]);
	return (NULL);
}

/*
** Returns index of first matching vector, or -1 if not found
*/

int				vector_search(t_vector *v, int (*cmp)(), void *item)
{
	size_t i = 0;

	while (i < v->amt)
	{
		if (cmp(v->data[i], item) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int				vector_delete(t_vector *v, size_t index)
{
	size_t i;
	ft_dprintf(STDIN_FILENO, "\namt: %d\n index: %d\n", v->amt, index);
	if (index <= 0 || index > v->amt)
		return (0);
	// v->data[index];
	// free(v->data[index]);
	v->data[index] = NULL;
	i = index;
	while (i < v->amt)
	{
		v->data[i] = v->data[i + 1];
		i++;
	}
	// if (!vector_resize(v, v->amt - 1))
		// return (0);
	// vector_resize(v, v->amt - 1);

	ft_dprintf(STDIN_FILENO, "\n\n\n VECTOR NEW SIZE: %d\n", v->amt);
	return (1);
}
