/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 12:38:41 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/05 17:51:49 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	find_length(int n)
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

char		*ft_itoa(int n)
{
	int		l;
	char	*arr;

	l = find_length(n);
	arr = (char *)malloc((l + 1) * sizeof(char));
		if (arr == NULL)
			return (NULL);
	arr[l] = '\0';
	if (n == 0)
		arr[0] = '0';
	if (n == -2147483648)
	{
		l--;
		arr[l] = '8';
		n /= 10;
	}
	if (n < 0)
	{
		arr[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		arr[l - 1] = (n % 10) + '0';
		n /= 10;
		l--;
	}
	return (arr);
}
