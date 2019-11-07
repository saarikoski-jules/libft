/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 21:11:30 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/07 12:43:05 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> //REMOVE


void ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *last;

	if (new == NULL)
	{
		return ;
	}
	if (*alst == NULL)
	{
		// printf("lstadd_back: start == NULL\n");
		alst = &new;
		// printf("%p\n", alst);
		return ;
	}
	// printf("lstadd_back: triggering lstlast\n");
	last = ft_lstlast(*alst);
	last->next = new;
}