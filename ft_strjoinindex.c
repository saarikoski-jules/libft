/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoinindex.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 15:03:19 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/20 15:43:39 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinindex(const char *s1, const char *s2, int index)
{
	char	*new;
	int		len1;
	int		len2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (index < 0)
		index = 0;
	if (index > len1)
		index = len1;
	new = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	ft_memcpy(new, s1, index * sizeof(char));
	ft_memcpy(new + index, s2, len2 * sizeof(char));
	ft_memcpy(new + index + len2, s1 + index, len1 - index);
	return (new);
}
