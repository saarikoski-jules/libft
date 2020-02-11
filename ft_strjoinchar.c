/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoinchar.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 18:00:50 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/11 18:13:49 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchar(char *str, char c)
{
	int		len;
	char	*new;

	if (str == NULL)
		str = ft_strdup("");
	len = ft_strlen(str);
	new = ft_recalloc(str, len + 2);
	new[len] = c;
	return (new);
}
