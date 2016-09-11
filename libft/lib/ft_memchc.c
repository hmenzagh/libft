#include	"libft.h"

int		ft_memchc(void *s, char c, int len)
{
	int 	i;
	int		y;
	char	*s_c;

	s_c = (char*)s;
	i = 0;
	y = 0;
	while(y++ < len)
		if(*s_c++ == c)
			++i;
	return (i);
}