/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clear_list.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/16 13:13:27 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/10/22 10:10:57 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	clear_list(t_dprintf_arg **head)
{
	t_dprintf_arg *tmp;
	t_dprintf_arg *cur;

	tmp = *head;
	cur = *head;
	while (tmp != NULL)
	{
		cur = tmp;
		tmp = tmp->next;
		if (cur->conv == s)
			free(cur->arg.s);
		free(cur);
		cur = NULL;
	}
	*head = NULL;
}
