/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 13:39:37 by jsaariko       #+#    #+#                */
/*   Updated: 2019/10/30 16:50:33 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	char *new;
	int i;
	int l;
	int j;

	i = 0;
	j = 0;
	l = ft_strlen(s1);
	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[l - 1]))
		l--;
	l -= i;
	new = (char *)malloc((l + 1)*sizeof(char));
	while (j < l)
	{
		new[j] = s1[i];
		j++;
		i++;
	}
	new[j] = '\0';
	return (new);
}