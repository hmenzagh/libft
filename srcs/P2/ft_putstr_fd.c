#include	"libft.h"

void	ft_putstr_fd(char const *s,int fd)
{
	write(fd, s, ft_strlen(s));
}