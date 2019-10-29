/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:24:42 by jsaariko       #+#    #+#                */
/*   Updated: 2019/10/28 18:24:42 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s)
{
	char	*dup;
	int		l;
	
	l = ft_strlen(s);
	dup = (char *)malloc(l);
	ft_strlcpy(dup, s, l);
	return(dup);
}