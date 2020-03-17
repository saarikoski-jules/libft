/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ftoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 18:03:40 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/15 16:24:42 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "includes/ft_ftoa.h"
#include <float.h>
#include <limits.h>

static char	*strjoin_free(char **str, char **c)
{
	char *new;

	if (!(*str) || !(*c))
		return (NULL);
	new = ft_strjoin(*str, *c);
	if (!new)
		return (NULL);
	free(*str);
	free(*c);
	*str = NULL;
	*c = NULL;
	return (new);
}

static char	*get_prec_str(double num, ssize_t prec, int *lst)
{
	int		last;
	int		d;
	char	*new_char;
	char	*final;

	if (num < 0)
		num *= -1;
	final = ft_strdup("");
	if (!final)
		return (NULL);
	last = get_last_dec(num, prec + 1);
	d = round_dec(&last, 5, num, prec);
	prec--;
	while (0 <= prec)
	{
		new_char = ft_lltoa_base(d, 10);
		final = strjoin_free(&new_char, &final);
		if (!final)
			return (NULL);
		d = round_dec(&last, 9, num, prec);
		prec--;
	}
	*lst = last;
	return (final);
}

static char	*gen_float_str(long long d, char *dec)
{
	char *main_str;
	char *tmp;

	if (d == LLONG_MIN)
		main_str = ft_strdup("-9223372036854775808");
	else
		main_str = ft_lltoa_base(d, 10);
	if (!main_str)
		return (NULL);
	tmp = ft_strjoin(main_str, ".");
	free(main_str);
	if (!tmp)
		return (NULL);
	main_str = ft_strjoin(tmp, dec);
	free(dec);
	free(tmp);
	return (main_str);
}

static char	*handle_precision(double num, ssize_t precision)
{
	char		*main_str;
	char		*dec;
	long long	d;
	int			last;

	main_str = NULL;
	dec = get_prec_str(num, precision, &last);
	if (!dec)
		return (NULL);
	d = (long long)num;
	if (last == 9)
	{
		if (num > 0)
			d++;
		else if (num < 0)
			d--;
	}
	main_str = gen_float_str(d, dec);
	if (!main_str)
		return (NULL);
	return (main_str);
}

char		*ft_ftoa(double num, ssize_t precision)
{
	char *main_str;
	char *neg_zero;

	main_str = NULL;
	if (precision > 0)
		main_str = handle_precision(num, precision);
	else if (precision == 0)
	{
		if (get_last_dec(num, 0) >= 5)
			num += 1;
		main_str = ft_lltoa_base((long long)num, 10);
	}
	if (1 / num < -FLT_MAX && num == 0)
	{
		neg_zero = ft_strjoin("-", main_str);
		free(main_str);
		if (!neg_zero)
			return (NULL);
		return (neg_zero);
	}
	if (!main_str)
		return (NULL);
	return (main_str);
}
