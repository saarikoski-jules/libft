#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char *ptr_copy;

	ptr_copy = ptr;
	while(n > 0)
	{
		*ptr_copy = c;
		ptr_copy++;
		n--;
	}
	return (ptr);
}