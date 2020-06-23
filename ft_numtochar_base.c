/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numtochar_base.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 10:48:36 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/02/16 15:44:11 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_numtochar_base(int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	return (n - 10 + 'A');
}
