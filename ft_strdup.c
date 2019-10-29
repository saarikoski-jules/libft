/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 14:17:21 by jsaariko       #+#    #+#                */
/*   Updated: 2019/10/29 19:31:18 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		l;

	l = ft_strlen(s);
	dup = (char *)malloc(l);
	ft_strlcpy(dup, s, l);
	return (dup);
}
