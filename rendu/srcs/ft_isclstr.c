#include	"libft.h"

int			ft_isclstr(t_clist *lst)
{
	if(lst->content == (void*)&(lst->content_size) && lst->content_size == 101)
		return (1);
	return (0);
}