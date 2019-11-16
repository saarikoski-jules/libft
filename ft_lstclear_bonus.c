/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 13:52:55 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/09 14:09:18 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;
	t_list *cur;

	cur = *lst;
	while (cur != NULL)
	{
		temp = cur;
		ft_lstdelone(cur, del);
		cur = temp->next;
	}
	*lst = NULL;
}
