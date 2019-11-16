/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 15:15:07 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/12 10:06:20 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_split(char const *s, char c, int end, int bool)
{
	int i;

	i = end;
	if (bool == 0)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	else if (bool == 1)
	{
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (i);
}

static int	str_amt(char const *s, char c)
{
	int i;
	int amt;

	i = 0;
	amt = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			amt++;
		}
		i++;
	}
	return (amt);
}

static char	**free_matrix(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**allocate_arr(char const *s, char c, int amt, char **arr)
{
	int start;
	int end;
	int i;

	start = 0;
	end = 0;
	i = 0;
	while (i < amt)
	{
		start = find_split(s, c, end, 0);
		end = find_split(s, c, start, 1);
		arr[i] = ft_substr(s, start, (end - start));
		if (arr[i] == NULL)
			return (free_matrix(arr));
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char		**ft_split(char const *s, char c)
{
	char	**arr;
	int		start;
	int		end;
	int		i;
	int		amt;

	if (!s)
		return (NULL);
	i = 0;
	start = 0;
	end = 0;
	amt = str_amt(s, c);
	arr = (char **)malloc(((amt + 1) * sizeof(char *)));
	if (arr == NULL)
		return (NULL);
	return (allocate_arr(s, c, amt, arr));
}
