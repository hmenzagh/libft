#include	"libft.h"

int			ft_memreallocsub(void **s, unsigned int start, size_t len)
{
	char	*chaine;

	if(!(chaine = ft_memsub(*s, start, len)))
		return (0);
	ft_memdel(s);
	*s = chaine;
	return (1);
}