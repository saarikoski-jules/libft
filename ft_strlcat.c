/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:24:47 by jsaariko       #+#    #+#                */
/*   Updated: 2019/10/28 18:24:48 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *s1, const char *s2, size_t n)
{
    size_t l;
    size_t i;

    i = 0;
    l = ft_strlen(s1);
    while(l < n)
    {
        s1[l] = s2[i];
        l++;
        i++;
    }
    s1[n] = '\0';
    return(l - i + ft_strlen(s2));
}