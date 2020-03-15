/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/23 22:39:15 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/15 16:24:27 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

int			find_len(char *s, char c)
{
	int i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (c == '\n')
		return (-1);
	return (i);
}

char		*gnl_realloc(char *orig, int size, int len)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(size * sizeof(char));
	if (!new)
		return (NULL);
	while (i < size)
	{
		new[i] = '\0';
		i++;
	}
	if (orig == NULL)
		return (new);
	i = 0;
	while (i < len)
	{
		new[i] = orig[i];
		i++;
	}
	free(orig);
	return (new);
}

t_gnl_fd	*add_fd(int fd, t_gnl_fd **store)
{
	t_gnl_fd *store_ptr;
	t_gnl_fd *iter;

	store_ptr = malloc(sizeof(t_gnl_fd));
	if (!store_ptr)
		return (NULL);
	store_ptr->fd = fd;
	store_ptr->next = NULL;
	store_ptr->rem = NULL;
	iter = *store;
	if (*store == NULL)
		*store = store_ptr;
	else
	{
		while (iter->next != NULL)
			iter = iter->next;
		iter->next = store_ptr;
	}
	return (store_ptr);
}

t_gnl_fd	*find_fd(int fd, t_gnl_fd **store)
{
	t_gnl_fd *store_ptr;

	store_ptr = *store;
	while (store_ptr != NULL)
	{
		if (store_ptr->fd == fd)
			return (store_ptr);
		store_ptr = store_ptr->next;
	}
	return (NULL);
}

void		rm_fd(t_gnl_fd *f, t_gnl_fd **head)
{
	t_gnl_fd *cur;
	t_gnl_fd *prev;

	cur = *head;
	prev = NULL;
	while (cur->next != NULL && cur->fd != f->fd)
	{
		prev = cur;
		cur = cur->next;
	}
	if (prev == NULL)
		*head = cur->next;
	else if (prev != NULL && cur->next)
		prev->next = cur->next;
	else if (prev != NULL && !cur->next)
		prev->next = NULL;
	free(f);
	f = NULL;
}
