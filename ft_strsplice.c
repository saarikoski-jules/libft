/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplice.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 17:31:03 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/12/07 17:56:09 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsplice(const char *string, size_t start, size_t del,
			const char *value)
{
	char	*new;
	int		len_new;
	size_t	str_len;
	size_t	value_len;

	if (!string || !value)
		return (NULL);
	str_len = ft_strlen(string);
	if (del > str_len - start)
		del = str_len - start;
	value_len = ft_strlen(value);
	len_new = str_len - del + value_len + 1;
	if (start > str_len || len_new < 0)
		return (NULL);
	if (len_new == 0)
		return (ft_strdup(""));
	new = (char *)calloc(len_new, sizeof(char));
	if (!new || len_new < 0)
		return (NULL);
	ft_strlcpy(new, string, start + 1);
	ft_strlcpy(new + start, value, value_len + 1);
	ft_strlcpy(new + start + value_len,
		string + start + del,
		str_len - start - del + 1);
	return (new);
}
