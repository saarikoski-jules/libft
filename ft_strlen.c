/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:25:02 by jsaariko       #+#    #+#                */
/*   Updated: 2019/10/28 18:25:02 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlen(const char *s)
{
	int l;

	l = 0;
	while(s[l] != '\0')
	{
		l++;
	}
	return (l);
}