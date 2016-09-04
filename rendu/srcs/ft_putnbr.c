#include	"libft.h"

void	ft_putnbr(int n)
{
	long x;

	x = n;
	if (n < 0)
	{
		ft_putchar('-');
		x = -x;
	}
	if (x >= 10)
	{
		ft_putnbr(x / 10);
		ft_putnbr(x % 10);
	}
	else
		ft_putchar(x + '0');
}