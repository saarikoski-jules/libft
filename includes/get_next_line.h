/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 16:26:15 by jsaariko       #+#    #+#                */
/*   Updated: 2020/01/03 12:08:43 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <stdlib.h>

typedef struct			s_gnl_fd
{
	int					fd;
	char				*rem;
	struct s_gnl_fd		*next;
}						t_gnl_fd;

int						get_next_line(int fd, char **line);
char					*gnl_realloc(char *orig, int size, int len);
int						find_len(char *s, char c);
t_gnl_fd				*add_fd(int fd, t_gnl_fd **store);
t_gnl_fd				*find_fd(int fd, t_gnl_fd **store);
void					rm_fd(t_gnl_fd *f, t_gnl_fd **head);

#endif
