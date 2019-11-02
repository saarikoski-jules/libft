/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 15:15:07 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/02 15:44:15 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nsearch(const char *s, int c, int i)
{
	while (s[i] != '\0')
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			return (i);
		i++;
	}
	if (c == 0)
		return (i);
	return (i);
}

static int	stramt(const char *s, char c)
{
	int i;
	int amt;

	i = 0;
	amt = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && c && s[i + 1])
			amt++;
		i++;
	}
	return (amt);
}

char		**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		k;
	int		amt;

	j = 0;
	i = 0;
	arr = (char **)malloc(((int)ft_strlen(s) - 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	amt = stramt(s, c);
	while (j <= amt)
	{
		k = i;
		i = nsearch(s, (int)c, i);
		i++;
		arr[j] = (char *)malloc((i - k) * sizeof(char));
		ft_strlcpy(arr[j], &s[k], i - k);
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
