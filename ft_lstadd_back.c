/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 21:11:30 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/05 22:15:13 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *last;

	if (alst == NULL || new == NULL)
		return ;
	last = ft_lstlast(*alst);
	last->next = new;
}