/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 12:38:41 by jsaariko      #+#    #+#                 */
/*   Updated: 2019/11/16 11:28:38 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*exceptions(int n)
{
	char	*arr;

	if (n == 0)
	{
		arr = (char *)malloc(2 * sizeof(char));
		arr[1] = '\0';
		arr[0] = '0';
	}
	if (n == -2147483648)
	{
		arr = (char *)malloc(12 * sizeof(char));
		ft_strlcpy(arr, "-2147483648", 12 * sizeof(char));
	}
	return (arr);
}

char		*ft_itoa(int n)
{
	int		l;
	char	*arr;

	if (n == -2147483648 || n == 0)
		return (exceptions(n));
	l = ft_numlen(n);
	arr = (char *)malloc((l + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	arr[l] = '\0';
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
