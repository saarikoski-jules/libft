/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 12:48:44 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/15 16:24:16 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include <unistd.h>

static char		*dup_line(char *orig, char *new, char c)
{
	int len;
	int i;
	int ret;

	i = 0;
	ret = find_len(new, c);
	len = find_len(orig, '\0');
	orig = gnl_realloc(orig, (ret + len + 1), len);
	if (orig == NULL)
		return (NULL);
	while (i < ret)
	{
		orig[len + i] = new[i];
		i++;
	}
	orig[len + i] = '\0';
	return (orig);
}

static void		handle_remainder(char **remainder, char **line_cpy)
{
	char *remainder_cpy;

	remainder_cpy = NULL;
	if (*remainder && find_len(*remainder, '\n') == -1)
	{
		*line_cpy = dup_line(*line_cpy, *remainder, '\0');
		free(*remainder);
		*remainder = NULL;
	}
	else if (*remainder && find_len(*remainder, '\n') != -1)
	{
		*line_cpy = dup_line(*line_cpy, *remainder, '\n');
		remainder_cpy = dup_line(remainder_cpy,
			*remainder + find_len(*remainder, '\n') + 1, '\0');
		free(*remainder);
		*remainder = NULL;
		*remainder = dup_line(*remainder, remainder_cpy, '\0');
		free(remainder_cpy);
	}
}

static int		read_input(t_gnl_fd *f, char **line_cpy, int ret)
{
	char	*buf;

	while (ret > 0)
	{
		buf = (char *)gnl_realloc(NULL, (BUFFER_SIZE + 1), 0);
		if (!buf)
			return (-1);
		ret = read(f->fd, buf, BUFFER_SIZE);
		if (ret <= 0)
		{
			free(buf);
			return (ret);
		}
		buf[ret] = '\0';
		if (find_len(buf, '\n') != -1)
		{
			*line_cpy = dup_line(*line_cpy, buf, '\n');
			f->rem = dup_line(f->rem, buf + find_len(buf, '\n') + 1, '\0');
			free(buf);
			return (ret);
		}
		*line_cpy = dup_line(*line_cpy, buf, '\0');
		free(buf);
	}
	return (ret);
}

static t_gnl_fd	*handle_list(int fd, int rm)
{
	static t_gnl_fd *store_first;
	t_gnl_fd		*f;

	if (rm == 1)
	{
		f = find_fd(fd, &store_first);
		rm_fd(f, &store_first);
		return (NULL);
	}
	if (find_fd(fd, &store_first) == NULL)
		f = add_fd(fd, &store_first);
	else
		f = find_fd(fd, &store_first);
	return (f);
}

int				get_next_line(int fd, char **line)
{
	t_gnl_fd		*f;
	int				ret;
	char			*line_cpy;

	line_cpy = NULL;
	f = handle_list(fd, 0);
	if (f == NULL || !line)
		return (-1);
	if (f->rem != NULL)
		handle_remainder(&f->rem, &line_cpy);
	if (f->rem == NULL)
	{
		ret = read_input(f, &line_cpy, 1);
		if (ret <= 0)
			f = handle_list(fd, 1);
	}
	if (f && line_cpy && f->rem)
		ret = 1;
	*line = line_cpy;
	if (!*line)
		*line = gnl_realloc(*line, 1, 0);
	if (!*line)
		ret = -1;
	return (ret);
}
