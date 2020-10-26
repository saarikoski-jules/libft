/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 17:39:16 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/10/26 17:40:16 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** If vector doesn't exist, returns 0. Else inits all params and returns 1
*/

int	vector_init(t_vector *v)
{
	if (v == NULL)
		return (0);
	v->item_size = 0;
	v->amt = 0;
	v->data = NULL;
	return (1);
}
