#include "libft.h"

double	ft_pow(double base, int exp)
{
	double	res;
	int		i;

	res = base;
	if (exp == 0)
		return (1.0);
	else if (exp < 0)
		i = exp * -1;
	else
		i = exp;
	while (i > 1)
	{
		res *= base;
		i--;
	}
	if (exp < 0)
		res = 1 / res;
	return (res);
}
