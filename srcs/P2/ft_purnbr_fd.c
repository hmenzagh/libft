#include	"libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	char	c;

	c = 0;
	if(n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if(n < 10)
	{
		c = (n + '0');
		write(fd, &c, 1);
	}
}