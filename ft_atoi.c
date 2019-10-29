/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 13:04:40 by jsaariko       #+#    #+#                */
/*   Updated: 2019/10/29 15:03:51 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	total;
	int	sign;

	i = 0;
	total = 0;
	sign = 1;
	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] != '\0')
	{
		total = 10 * total + (s[i] - '0');
		i++;
	}
	return (total * sign);
}