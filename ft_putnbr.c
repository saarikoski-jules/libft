#include "libft.h"

void ft_putnbr(int c)
{
	if (c == -2147483648)
	{
		ft_putstr("-2147483648");
	}
	else 
	{
		if (c < 0)
		{
			ft_putchar('-');
			c *= -1;
		}
		if (c >= 10)
		{
			ft_putnbr(c/10);
		}
		int num = c%10;
		ft_putchar(num + '0');
	}
}