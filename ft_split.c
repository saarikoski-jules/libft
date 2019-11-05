/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 15:15:07 by jsaariko       #+#    #+#                */
/*   Updated: 2019/11/05 15:31:30 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int find_start(char const *s, char c, int end)
{
	int i;

	i = end;
	while (s[i] == c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int find_end(char const *s, char c, int start)
{
	int i;

	i = start;
	while(s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int str_amt(char const *s, char c)
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

char **ft_split(char const *s, char c)
{
	char **arr;
	int start;
	int end;
	int i;
	int amt;

	if (!s)
		return (NULL);
	i = 0;
	amt = str_amt(s, c);
	arr = (char **)malloc(((amt + 1) * sizeof(char *)));
	start = 0;
	end = 0;
	while (i < amt)
	{
		start = find_start(s, c, end);
		end = find_end(s, c, start);
		arr[i] = ft_substr(s, start, (end - start));
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
