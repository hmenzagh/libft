#include	"libft.h"

void		ft_clstdelone(t_clist **todel)
{
	if(*todel)
	{
		if((*todel)->content)
			free((*todel)->content);
		free(*todel);
		*todel = NULL;
	}
}