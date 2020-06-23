/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putbytes_fd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 17:36:29 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/06/23 10:07:58 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_putbytes_fd(const void *bytes, size_t n, int fd)
{
	const char *bytes_cpy;

	if (bytes == NULL)
		return ;
	bytes_cpy = bytes;
	while (n > 0)
	{
		n--;
		ft_putchar_fd(((bytes_cpy[n] & (1LL << 7)) != 0) + '0', fd);
		ft_putchar_fd(((bytes_cpy[n] & (1LL << 6)) != 0) + '0', fd);
		ft_putchar_fd(((bytes_cpy[n] & (1LL << 5)) != 0) + '0', fd);
		ft_putchar_fd(((bytes_cpy[n] & (1LL << 4)) != 0) + '0', fd);
		ft_putchar_fd(((bytes_cpy[n] & (1LL << 3)) != 0) + '0', fd);
		ft_putchar_fd(((bytes_cpy[n] & (1LL << 2)) != 0) + '0', fd);
		ft_putchar_fd(((bytes_cpy[n] & (1LL << 1)) != 0) + '0', fd);
		ft_putchar_fd(((bytes_cpy[n] & (1LL << 0)) != 0) + '0', fd);
		if (n != 0)
			ft_putchar_fd(' ', fd);
	}
}
