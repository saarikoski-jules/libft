/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gen_arg_list.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:05:00 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/10/22 10:02:56 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf_arg	*gen_elem(t_printf_arg **head)
{
	t_printf_arg	*cur;
	t_printf_arg	*new;

	new = malloc(sizeof(t_printf_arg));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->pad_type = p_normal;
	new->field_width = 0;
	new->precision = -1;
	if (*head == NULL)
		*head = new;
	else
	{
		cur = *head;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
	}
	return (new);
}

int				store_conv(char chr, t_printf_arg **cur, va_list ap)
{
	if (ft_strchr("uxX", chr))
		store_uint(chr, cur, ap);
	else if (ft_strchr("di", chr))
		store_int(chr, cur, ap);
	else if (ft_strchr("c%", chr))
		store_char(chr, cur, ap);
	else if (ft_strchr("f", chr))
		store_float(cur, ap);
	else if (ft_strchr("sp", chr))
	{
		if (store_other(chr, cur, ap) == -1)
			return (-1);
	}
	return (1);
}

char			*get_format_str(const char *str, int len)
{
	char	*format_str;

	format_str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!format_str)
		return (NULL);
	ft_strlcpy(format_str, str, len + 1);
	return (format_str);
}

int				parse_arg(t_printf_arg **head, char **format_str, va_list ap,
							char conv)
{
	t_printf_arg *cur;

	cur = gen_elem(head);
	if (!cur)
		return (-1);
	manage_parser(&cur, *format_str, ap);
	if (store_conv(conv, &cur, ap) == -1)
	{
		free(*format_str);
		*format_str = NULL;
		return (-1);
	}
	return (1);
}

int				gen_arg_list(t_printf_arg **head, const char *str, va_list ap)
{
	char	*format_str;
	int		i;
	int		len;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			len = ft_strmatch(str + i, "0123456789-*.");
			format_str = get_format_str(str + i, len);
			if (!format_str)
				return (-1);
			i += len;
			if (ft_strchr("cspdiuxXf%", str[i]) != NULL)
			{
				if (parse_arg(head, &format_str, ap, str[i]) == -1)
					return (-1);
			}
			free(format_str);
		}
		i++;
	}
	return (1);
}
