/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ftoa_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 15:37:33 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/14 11:59:51 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	get_last_dec(double num, ssize_t precision)
{
	int			i;
	long long	d;
	double		f;

	i = 0;
	if (num > LLONG_MAX || num < LLONG_MIN)
		num = 0.0;
	d = (long long)num;
	f = num - d;
	while (i < precision)
	{
		f = f * 10;
		d = (int)f;
		f = f - d;
		i++;
	}
	return (d);
}

int	round_dec(int *last, int comp, double num, int prec)
{
	int d;

	d = get_last_dec(num, prec);
	if (*last >= comp)
	{
		*last = d;
		if (d == 9)
			d = 0;
		else
			d++;
	}
	return (d);
}
