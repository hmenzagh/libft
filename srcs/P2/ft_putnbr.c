#include	"libft.h"

void	ft_putnbr(int n)
{
	if(n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if(n < 10)
		ft_putchar(n + '0');
}