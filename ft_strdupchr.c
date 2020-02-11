/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdupchr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 04:48:30 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/01 15:13:33 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdupchr(const char *str, const char *charset)
{
	int		i;
	char	*res;

	if (str == NULL)
		return (ft_strdup(""));
	i = ft_strchrset(str, charset);
	if (i == -1)
	{
		res = ft_strdup(str);
		return (res);
	}
	res = (char *)malloc((i + 1) * sizeof(char));
	ft_strlcpy(res, str, i + 1);
	return (res);
}
