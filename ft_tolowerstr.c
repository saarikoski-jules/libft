/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolowerstr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 14:04:51 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/16 14:23:18 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tolowerstr(char **str)
{
	int i;

	i = 0;
	while ((*str)[i] != '\0')
	{
		(*str)[i] = ft_tolower((*str)[i]);
		i++;
	}
}
