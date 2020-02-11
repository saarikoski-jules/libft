/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/16 11:28:51 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/11 15:47:04 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int n)
{
	int l;

	l = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		l++;
	while (n != 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}
