/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 13:04:40 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/06/22 18:25:19 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int					i;
	unsigned long long	total;
	int					sign;

	i = 0;
	total = 0;
	sign = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] <= '9' && s[i] >= '0')
	{
		total = 10 * total + (s[i] - '0');
		i++;
	}
	if (total > 9223372036854775807 && sign == -1)
		total = 0;
	else if (total > 9223372036854775807 && sign == 1)
		total = -1;
	return ((int)(total * sign));
}
