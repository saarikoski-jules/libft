#include "libft.h"

char *ft_strdup(const char *s)
{
	char *dup;

	dup = (char *)malloc(ft_strlen(s));
	ft_strcpy(dup, s);
	return(dup);
}