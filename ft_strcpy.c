#include "libft.h"

char *ft_strcpy(char *s1, const char *s2)
{
	char	*str;
	int		l;

	l = ft_strlen(s2);
	str = ft_memmove(s1, s2, l);
	str[l] = '\0';
	return (str);
}