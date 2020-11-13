/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplice.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 17:31:03 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/11/13 11:38:13 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strsplice(const char *string, int start, int del, char *value)
{
	char *new;
	int len_new;
	int str_len;

	str_len = ft_strlen(string);
	int value_len = ft_strlen(value);
	len_new = str_len - del + value_len + 1;
	new = (char *)calloc(len_new, sizeof(char));
	if (!new || len_new < 0)
		return (NULL);
	if (len_new == 0)
		return (ft_strdup(""));
	ft_strlcpy(new, string, start + 1);
	// ft_dprintf(STDOUT_FILENO, "splice: %s\n", new);
	ft_strlcpy(new + start, value, value_len + 1);
	// ft_dprintf(STDOUT_FILENO, "splice: %s\n", new);
	ft_strlcpy(new + start + value_len, string + start + del, str_len - start - del + 1);
	// ft_dprintf(STDOUT_FILENO, "splice: %s\n\n", new);
	return (new);
}