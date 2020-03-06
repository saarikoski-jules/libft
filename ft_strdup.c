/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 14:17:21 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/06 14:53:07 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		l;

	l = ft_strlen(s) + 1;
	dup = (char *)malloc(l * (sizeof(char)));
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, s, l);
	return (dup);
}
