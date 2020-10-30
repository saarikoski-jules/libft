/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_print.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 20:54:03 by limartin      #+#    #+#                 */
/*   Updated: 2020/10/30 13:09:26 by lindsay       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Both these functions print the contents of a vector.
** vector_debug will display additional information on vector size & items.
**
** Info/contents of vector 'v' is printed to file descriptor specified by 'fd'.
** 'print' is a pointer to a function that can print the datatype of the
** vector 'v'.
**
** On error, -1 is returned.
**
** The function pointed to by print should receive two arguments:
** 1) An int representing the file descriptor to write to.
** 2) An index of the vector to display, matching the vector's datatype.
** Ideally, it should also return -1 on error.
*/

int		vector_print(int fd, t_vector *v, int (*print)())
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	while (i < v->amt && ret > -1)
	{
		if (ret > -1)
			ret = print(fd, v->data[i]);
		ret = (ret > -1) ? write(fd, "\n", 0) : ret;
		i++;
	}
	return (ret);
}

int		vector_debug(int fd, t_vector *v, int (*print)())
{
	int ret;

	ret = write(fd, "Number of items:		", 18);
	ft_putnbr_fd(v->amt, fd);
	ret = (ret > -1) ? write(fd, "\nItem size:			", 15) : ret;
	ft_putnbr_fd(v->item_size, fd);
	ret = (ret > -1) ? write(fd, "\nTotal size:			", 16) : ret;
	ft_putnbr_fd((v->amt * v->item_size), fd);
	ret = (ret > -1) ? write(fd, "\n", 1) : ret;
	if (ret > -1)
		ret = vector_print(fd, v, print);
	return (ret);
}
