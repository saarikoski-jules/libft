#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

//----------------------------------------------------------------------

// static int	nbr_bits(unsigned int nbr)
// {
// 	int				i;

// 	i = 1;
// 	while ((nbr = nbr >> 1))
// 		i++;
// 	return (i);
// }

// static void	cond1(unsigned int ch, int *i, char *buff)
// {
// 	buff[(*i)++] = ((ch >> 18) & 7) | 240;
// 	buff[(*i)++] = ((ch >> 12) & 63) | 128;
// }

// static void	putwchart(int wchar, int *len, char *buff)
// {
// 	unsigned int	ch;
// 	int				n;
// 	int				i;

// 	i = 0;
// 	ch = (unsigned int)wchar;
// 	n = nbr_bits(ch);
// 	if (n > 7 && ((*len += 1)))
// 	{
// 		if (n > 11 && ((*len += 1)))
// 		{
// 			if (n > 16 && ((*len += 2)))
// 				cond1(ch, &i, buff);
// 			else if ((*len += 1))
// 				buff[i++] = ((ch >> 12) & 15) | 224;
// 			buff[i++] = (ch & 63) | 128;
// 		}
// 		else if ((*len += 1))
// 			buff[i++] = ((ch >> 6) & 31) | 192;
// 		buff[i++] = (ch & 63) | 128;
// 	}
// 	else if ((*len += 1))
// 		buff[i++] = ch;
// }

// void		ft_putchar_f(int c, int fd)
// {
// 	int				len;
// 	char			buff2[10];

// 	len = 0;
// 	putwchart(c, &len, buff2);
// 	write(fd, buff2, len);
// }

//--------------------------------------------------------------------------

void test_putchar()
{

	//ft_putchar_fd('Ã', 1);
	char happy[] = { 0xe2, 0x98, 0xba };
	write(1, happy , 4);
}

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

   char s1[100] = "Geeksfor"; 
//   printf("ft_memcpy: %s\n", ft_memcpy(((void *)0), s1, 3));

   char s2[100] = "Geeksfor"; 
	printf("memcpy: %s\n", memcpy(((void *)0), s1, 3));

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
	// char copy_from[30] = "";
	// char copy_to[30] = "123456789ABCDEF";
	// char copy_to2[30] = "123456789ABCDEF";

	// char buff1[30] = "abcdefghijklmnopqrstuvwxyz";
	// char buff2[30] = "abcdefghijklmnopqrstuvwxyz";
	// char *src = "string with\200inside !";

	// printf("%p\n", ft_memccpy(buff1, src, '\200', 30));
	// printf("%s - %s\n", buff1, src);
	// printf("%p\n", memccpy(buff2, src, '\200', 30));
	// printf("%s - %s\n", buff2, src);

	char src[] = "m !";
	char buff1[22];
	char buff2[22];

	printf("memccpy: %s\n", memccpy(buff1, src, 'm', 22));
	printf("ft_memccpy: %s", ft_memccpy(buff2, src, 'm', 22));

}

void test_memmove(void)
{
//	char copy_to[] = "123456789ABCDEF";	

   char c1[100] = "im a string";
   char c2[100];
   char b[100];
//    ft_memmove(NULL, NULL, strlen(c1)+1); 
//    memmove(NULL, NULL, strlen(c2)+1);
	// memmove(NULL, b, 5);
// printf("%s\n", c2);
	ft_memmove(NULL, NULL, 5);
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

void test_strlcpy()
{
	char s1[] = "whazzau";
	char s2[] = "123456789abcdefghijklmnopqrs";

	char *s3 = "I'm super confident whoa !\0Please help aa\n";
	char b1[20];
	char b2[20];

	char *s4 = "BBBB";
	char b3[20];
	char b4[20];

	char *s5 = "hello !";

	// printf("original size: %zu", strlcpy(b3, "", 2));
	// printf("ft size: %zu", ft_strlcpy(b4, "", 2));
	// printf("%s\n", b3);	
	// printf("%s\n", b4);	

	printf("size of orig: %zu\n", strlcpy(b3, s5, 20));
	printf("size of mine: %zu\n", ft_strlcpy(b4, s5, 20));
	printf("stored in orig: %s\n", b3);	
	printf("stored in mine: %s\n", b4);


	// printf("%zu\n", ft_strlcpy(b3, s4, 20));
	// printf("%zu\n", strlcpy(b4, s4, 20));
	// printf("ft_strlcpy: %s\n", b3);
	// printf("strlcpy: %s\n", b4);
}

void test_strlcat()
{
	char s1[100] = "123456789abcdefghijklmn";
	char s2[100] = "123456789abcdefghijklmn";
	char src[] = "I have no idea what I'm doing";


	char *s = "I'm super confident whoa !\0Please help aa\n";
	char b1[100] = "there is no stars in the sky";
	char b2[100] = "there is no stars in the sky";

	// ft_strlcat(b1, s, 40);
	// strlcat(b2, s, 40);


	printf("ft_strlcat = %zu\n", ft_strlcat(s1, src, 0));
	printf("strlcat = %zu\n", strlcat(s2, src, 0));
	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%s\n", src);
}

void test_strdup()
{
	char s1[] = "whazzup";
	char *s2;
	char *s3;
	s2 = strdup(s1);
	s3 = ft_strdup(s1);
	printf("original result: %s\n", s2);
	printf("my result: %s\n", s3);
	//printf("%s\n", s1);

	//protect malloc return
	// char *str;
	// char *tmp = "I malloc so I am.";

	// str = ft_strdup(tmp);
	//empty string
	//allocate the right size
	//add \0 to the end

}

void test_strchr()
{
	char s1[] = "123456789abcdefghijklmnopqrs";

	printf("%s\n", ft_strchr(s1, '9'));
}

void test_strrchr()
{
	char s1[] = "123456789abcdefghijklm9nopqrs";

	printf("%s\n", ft_strrchr(s1, 't'));
}

void test_strnstr()
{
	// char s1[] = "12345a6789abcdefghijklm9nopqrs";
	// char s2[] = "";

	// char s3[] = "MZIRIBMZIRIBMZE123";
	// char s4[] = "MZIRIBMZE";
	// size_t max = strlen(s2);
	// printf("orig: %s\n", strnstr(s4, s3, max));
	// printf("mine: %s\n", ft_strnstr(s4, s3, max));

	char *s1 = "MZIRIBMZERIBMZE123";
	char *s2 = "MZIRIBMZE";
	char *i1 = strnstr(s1, s2, 8);
	char *i2 = ft_strnstr(s1, s2, 8);

	// char * big = "123456789";
	// char * little = "9";
	// char *i1 = strnstr(big, little, 9);
	// char *i2 = ft_strnstr(big, little, 9);

	printf("%s, %s", i1, i2);

	// printf("%s\n", ft_strnstr(s1, s2, 20));
	// printf("%s\n", s1);
	// printf("%s\n", s2);
}

void test_strncmp()
{
	char s1[] = "\x12\xad";
	char s2[] = "\x12\xff\x65\x12\xbd\xde\x02";
	int n = 4;

	printf("%d\n", strncmp(s1, s2, n));
	printf("%d\n", ft_strncmp(s1, s2, n));
}

void test_atoi()
{
	char s1[] = "-2147483648";

	ft_atoi(s1);
	printf("%d", ft_atoi(s1));
	printf("%d", atoi(s1));
}

void test_memmove2()
{
	char str1[] = "123456789abcdefg";
	char str2[] = "123456789abcdefg";

	printf("%s\n", ft_memmove(str1, str1, 4));
	printf("%s\n", memmove(str2, str2, 4));
}

void test_calloc()
{
	char	*str1;
	char	*str2;

	str1 = ft_calloc(0, sizeof(char));
	str2 = calloc(0, sizeof(char));
	
	for(int i = 0; i < 7; i++)
	{
		str1[i] = i + '0';
	}
	for(int j = 0; j < 7; j++)
	{
		str2[j] = j + '0';
	}

	printf("%s\n", str2);
	printf("%s\n", str1);
}

void	test_substr()
{
	char str1[] = "123456789abcdef";
	char *str2;

	str2 = ft_substr("abababa", 0, 1);
	printf("%s\n", str2);
}

void test_strjoin()
{
	char str1[] = "123456789";
	char str2[] = "abcdefg";
	char *str3;

	//Pritect malloc

	str3 = ft_strjoin(NULL, NULL);
	printf("%s\n", str3);
}

void test_strtrim()
{
	// char str1[] = "labg";
	// char str2[] = "";
	// char *str3;

	//empty input, full blank input etc
	//protect malloc

	// str3 = ft_strtrim(str1, str2);
	// printf("%s\n", str3);

	// char *s3 = "";
	// char *s4 = "";
	// char *ret = ft_strtrim("", str2);

	char *s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";

	char *ret = ft_strtrim(s1, " \n\t");

	printf("%s\n", ret);

}

void test_itoa()
{
	printf("%s", ft_itoa(0));
}

char function(unsigned int i, char c)
{
	printf("%d\n", i);
	return (c - 32);
}

void test_strmapi()
{
	char str[] = "abcdefghijklmn";
	char (*f)(unsigned int, char) = &function;

	printf("%s", ft_strmapi("0", f));
}

void test_split()
{
	int i;
	// char const str[] = "";
	// char **arr = ft_split(NULL, 'a');

	char *s = "      split       this for   me  !       ";

	char **result = ft_split(s, ' ');

	i = 0;
	while (result[i])
	{
		printf("string %d: %s\n", i, result[i]);
		// printf("pointer %p\n", arr[i]);
		i++;
	}
}

void test_lstnew()
{
	t_list *first = ft_lstnew("yo");
	printf("%s\n", first->content);
}

void delete(void *item)
{
	item = NULL;
}

void *iter(void *item)
{
	printf("iter: %s\n", item);
	return (item);
}

void item(void *item)
{
	printf("mapped array item: %s\n", item);
}

void test_lst()
{
	t_list *one = ft_lstnew("one");
	t_list *two = ft_lstnew("two");
	t_list *three = ft_lstnew(NULL);
	t_list *four = ft_lstnew("four");
	
	// ft_lstadd_front(&four, three);
	// printf("%s\n", four->next->content);
	// ft_lstadd_front(&three, two);
	// ft_lstadd_front(&two, one);

	t_list *head;

	head = NULL;
	
	ft_lstadd_back(&head, one);
	ft_lstadd_back(&one, two);
	ft_lstadd_back(&two, three);
	ft_lstadd_back(&three, four);
	printf("head: %p", &head);

	t_list *mapped;

	void (*del)(void *) = &delete;
	void *(*f)(void *) = &iter;
	void (*third)(void *) = &item;
	mapped = ft_lstmap(one, f, delete);
	printf("mapped: %p\n", &mapped);
	ft_lstiter(mapped, third);

	// ft_lstiter(one, iter);

	// printf("last item's value: %s\n", ft_lstlast(one)->content);
	// printf("amt of items: %d\n", ft_lstsize(one));

	//lstaddback doesnt work with null???

	// t_list *l = ft_lstnew(strdup("nyacat"));
	// t_list *n = ft_lstnew(strdup("OK"));

	// ft_lstadd_front(&l, n);
	// printf("%s\n", l->content);

	// ft_lstclear(&one, del);

	// t_list *l = ((void *)0);
	// t_list *n = ft_lstnew(strdup("OK"));

	// ft_lstadd_back(&l, n);
	// printf("%p == %p\n", l, n);
	// printf("%s == OK\n", l->content);


}

int main()
{


	// printf("%s\n", ft_substr("bbbbaaabababa", 4, (7 - 4)));
	// printf("%s\n", ft_substr("bbbbaaabababa", 8, (9 - 8)));
	// printf("%s\n", ft_substr("bbbbaaabababa", 10, (11 - 10)));
	// printf("%s\n\n\n", ft_substr("bbbbaaabababa", 12, (13 - 12)));

	// char *str2 = ft_substr("abababa", 0, 1);
	// printf("%s\n", str2);
	// jelle_bonus();
	// test_substr();
	
	ft_memset(NULL, 2, 2);
	return (0);
}

//segfault strnstr and memmove with single null param


//atoi long longs longs longs
//strncmp CRASHES in all caps
// gcc libft_criterion_test/test_libft_criterion.c -lcriterion -Llibft -lft