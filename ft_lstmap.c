/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 17:09:34 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/07 13:41:23 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> //REMOVE

// void	*ft_lstiter(t_list *lst, void (*f)(void *))
// {
// 	t_list *temp;

// 	temp = lst;
// 	while (temp != NULL)
// 	{
// 		f(temp->content);
// 		temp = temp->next;
// 	}
// }

// void testing(void *item)
// {
// 	printf("iterating through new list in lstmap: %s\n", item);
// }



// t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	// t_list *temp;
// 	// void (*item)(void *) = &testing;
// 	t_list *new_first;
	
// 	new_first = NULL;
// 	// temp = lst;
// 	while (lst != NULL)
// 	{
// 		ft_lstadd_back(&new_first, ft_lstnew(f(lst->content)));
// 		// printf("new_first = %p", &new_first);
// 		lst = lst->next;
// 		// new = new->next;
// 	}

// 	if (1 == 2)
// 		del(lst);
// 	printf("new_first: %p\n", new_first);

// 	// ft_lstiter(&new_first, item);
// 	t_list *please; 
// 	please = NULL;
// 	please = new_first;
// 	printf("please: %p", please);
// 	// t_list *start = new_first;
// 	// printf("start: %s\n", &start->content);
// 	return (new_first);
// 	//take lst
// 	//iterate over it
// 	//apply function f to each item
// 	//save result to new list
// 	//return pointer to start of the new list
// 	//if any of it fails, apply delete function to content of the element

// }

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new = NULL;

	if (lst != NULL)
	{
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
			del(new->content);
		new->next = ft_lstmap(lst->next, f, del);
	}
	return (new);
}