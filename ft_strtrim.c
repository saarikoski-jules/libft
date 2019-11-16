/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 13:39:37 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/14 17:02:09 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		find_match(char const *s1, char const *set)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < (int)ft_strlen(set))
	{
		if (set[i] == s1[j])
		{
			j++;
			i = -1;
		}
		i++;
	}
	return (j);
}

static int		find_match_back(char const *s1, char const *set)
{
	int i;
	int k;

	i = 0;
	k = (int)ft_strlen(s1);
	while (i < (int)ft_strlen(set))
	{
		if ((set[i] == s1[k - 1]) && k != 0)
		{
			k--;
			i = -1;
		}
		i++;
	}
	return (k);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		j;
	int		k;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	j = find_match(s1, set);
	k = find_match_back(s1, set);
	if (k - j > 0)
	{
		trimmed = (char *)malloc((k - j + 1) * sizeof(char));
		if (trimmed == NULL)
			return (NULL);
		ft_strlcpy(trimmed, &s1[j], k - j + 1);
	}
	else
		trimmed = ft_strdup("");
	return (trimmed);
}
