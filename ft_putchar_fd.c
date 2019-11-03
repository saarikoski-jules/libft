/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 13:37:58 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/03 13:05:22 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	//If char is not ascii, convert to utf-8
	//check how many bytes
	//use write to printf it out
	//but how will they even pass these values to ft_putchar_fd as they can only pass chars...?
	write(fd, &c, 1);
}
