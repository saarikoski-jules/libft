/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 14:11:29 by jsaariko      #+#    #+#                 */
/*   Updated: 2019/10/29 14:32:11 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int c, int fd)
{
	int num;

	if (c == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else
	{
		if (c < 0)
		{
			ft_putchar_fd('-', fd);
			c *= -1;
		}
		if (c >= 10)
		{
			ft_putnbr_fd(c / 10, fd);
		}
		num = c % 10;
		ft_putchar_fd(num + '0', fd);
	}
}
