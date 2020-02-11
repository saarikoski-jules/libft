/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchrset.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/01 15:02:49 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/11 15:51:07 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchrset(const char *str, const char *charset)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (0);
	if (charset == NULL)
		return (ft_strlen(str));
	while (str[i] != '\0')
	{
		j = 0;
		while (charset[j] != '\0')
		{
			if (str[i] == charset[j])
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}
