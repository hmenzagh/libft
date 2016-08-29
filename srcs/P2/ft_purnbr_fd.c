#include	"libft.h"

void	ft_putnbr_fd(int n, int fd);
{
	if(n >= 10)
	{
		ft_putnbr(n / 10, fd);
		ft_putnbr(n % 10, fd);
	}
	if(n < 10)
		write(fd, &(n + '0'), 1);
}