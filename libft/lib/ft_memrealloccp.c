#include	"libft.h"

int		ft_memrealloccp(void **dst, void *src, size_t len_tot, size_t len_cp)
{
	if(ft_realloc(dst, len_tot - len_cp, len_tot) == -1)
		return (0);
	ft_memcat(*dst, src, len_tot - len_cp, len_cp);
	return (1);
}
