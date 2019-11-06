/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 20:31:52 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/05 22:14:13 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> //REMOVE

int	ft_lstsize(t_list *lst)
{
	t_list *temp;
	int i;

	if (lst == NULL)
		return (0);
	temp = lst;
	i = 1;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}