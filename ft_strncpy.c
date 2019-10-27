#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char	*str;

	str = ft_memmove(s1, s2, n);
	return (str);
}