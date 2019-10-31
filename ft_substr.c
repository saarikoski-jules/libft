/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 10:47:15 by jsaariko       #+#    #+#                */
/*   Updated: 2019/10/30 11:15:56 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	char			*ptr;
	unsigned int	i;

	new = (char *)malloc(len*sizeof(char) + 1);
	if (new == NULL)
	{
		return (NULL);
	}
	ptr = new;
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (ptr);
}