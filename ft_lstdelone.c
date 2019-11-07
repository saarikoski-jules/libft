/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 21:13:48 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/06 16:44:15 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL && del != NULL)
	{
		del(lst->content);
		free(lst);
	}
}

// void	ft_lstdelone(t_list **lst, void (*del)(void *))
// {
// 	if (lst != NULL && del != NULL)
// 	{
// 		del((*lst)->content);
// 		free(*lst);
// 		*lst = NULL;
// 	}
// }
