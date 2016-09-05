#include	"libft.h"

void		ft_strreallocsub(char **s, unsigned int start, size_t len)
{
	char	*chaine;

	if(!(chaine = ft_strsub(*s, start, len)))
		return ;
	ft_memdel((void*)s);
	*s = chaine;
}