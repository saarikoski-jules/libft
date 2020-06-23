/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 18:25:11 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/06/23 10:09:00 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	get_decimal(const char *str)
{
	double	dec;
	int		i;

	dec = 0.0;
	i = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		dec = 10 * dec + (str[i] - '0');
		i++;
	}
	i *= -1;
	dec *= ft_pow(10, i);
	return (dec);
}

double	ft_atof(const char *str)
{
	int		i;
	double	total;
	int		sign;

	i = 0;
	total = 0.0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		total = 10 * total + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		total += get_decimal(str + i + 1);
	return ((total * sign));
}
