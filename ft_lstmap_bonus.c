/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 17:09:34 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/08 17:54:05 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;

	new = NULL;
	if (lst != NULL)
	{
		new = ft_lstnew(f(lst->content));
		if (new != NULL)
			new->next = ft_lstmap(lst->next, f, del);
		else
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
	}
	return (new);
}
