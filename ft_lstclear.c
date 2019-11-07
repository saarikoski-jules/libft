/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 13:52:55 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/06 17:07:21 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list	**lst, void (*del)(void *))
{
	t_list *temp;

	temp = *lst;
	while (temp != NULL)
	{
		ft_lstdelone(temp, del);
		temp = temp->next;
	}
	free(temp);
	*lst = NULL;
}