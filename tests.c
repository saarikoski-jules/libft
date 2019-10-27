#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "libft.h"

void test_isalnum()
{
	int c;

	c = 'l';
	if ((ft_isalnum(c) > 0 && isalnum(c) > 0) || (ft_isalnum(c) == 0 && isalnum(c) == 0))
	{
		printf("%d, works", c);
	}
	else
	{
		printf("shit");
	}
}

void test_memcpy(void)
{
//	char copy_from[] = "I'm in so much pain right now";
//	char copy_to[] = "123456789ABCDEF";

//	printf("%s\n", copy_from);
//	printf("%s\n", copy_to);
//	ft_memcpy(copy_to, copy_from, 5);
//	printf("%s\n", copy_from);
//	printf("%s\n", copy_to);

   char csrc[100] = "Geeksfor"; 
   ft_memcpy(csrc+5, csrc, strlen(csrc)+1); 
   printf("%s\n", csrc); 

//	memcpy(copy_to+5, copy_to, strlen(copy_to)+1);
//	printf("%s\n", copy_to);
}

void test_memset(void)
{
	char copy_to[] = "123456";
	printf("%s\n", copy_to);
	ft_memset(copy_to, '.', 3);
	printf("%s\n", copy_to);
}

void test_bzero(void)
{
	char copy_to[] = "123456";

	printf("%s\n", copy_to);
	ft_bzero(copy_to, 3);
	printf("%s\n", copy_to);
	printf("%s\n", copy_to + 3);
}

void test_memccpy(void)
{
	char copy_from[] = "I'm in so much pain right now";
	char copy_to[] = "123456789ABCDEF";

	printf("%p\n", ft_memccpy(copy_to, copy_from, 's', 30));
	printf("%s - %s\n", copy_from, copy_to);
}

void test_memmove(void)
{
//	char copy_to[] = "123456789ABCDEF";	

   char csrc[100] = "Geeksfor"; 
   ft_memmove(csrc+5, csrc, strlen(csrc)+1); 
   printf("%s\n", csrc);

//	memmove(copy_to+5, copy_to, strlen(copy_to)+1);
//	printf("%s\n", copy_to);
}

void test_memchr()
{
	char	str[] = "I'm a string yall";
	int		c = 'a';

	printf("%p, %s\n", ft_memchr(str, c, 16), (char *)memchr(str, c, 16));
	printf("%p, %s\n", memchr(str, c, 16), (char *)memchr(str, c, 16));
}

void test_memcmp(char *s1, char *s2, size_t n)
{
	if ((ft_memcmp(s1, s2, n) == 0 && memcmp(s1, s2, n) == 0)
	|| (ft_memcmp(s1, s2, n) < 0 && memcmp(s1, s2, n) < 0)
	|| (ft_memcmp(s1, s2, n) > 0 && memcmp(s1, s2, n) > 0))
	{
		printf("ft_memcmp ok\n");
	}
	else
	{
		printf("ft_memcmp fail\n");
	}	
}

void test_strcpy()
{
	char s1[] = "whazzau";
	char s2[] = "123456789abcdefghijklmnopqrs";

	printf("%s\n", ft_strcpy(s2, s1));
	printf("%s\n", s1);
	printf("%s\n", s2);
}

void test_strncpy()
{
	char s1[] = "whazzau";
	char s2[] = "123456789abcdefghijklmnopqrs";

	
	printf("%s\n", ft_strncpy(s2, s1, 2));
	printf("%s\n", s1);
	printf("%s\n", s2);
}

void test_strdup()
{
	char s1[] = "123456789abcdefghijklmnopqrs";
	char *s2;

	s2 = strdup(s1);
	printf("%s\n", s2);
	printf("%s\n", s1);
}

int main()
{
	test_strncpy();
	return (0);
}
