#include	"libft.h"

void		ft_bzero(void *s, size_t n)
{
	char	*chaine;

	chaine = (char*)s;
	while(n-- > 0)
		*chaine++ = 0;
}