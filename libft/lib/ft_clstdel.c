#include	"libft.h"

void		ft_clstdel(t_clist **todel)
{
	t_clist	**ptr;

	ptr = NULL;
	ft_findclstr(todel);
	(*todel)->prev->next = NULL;
	while(*todel)
	{
		*ptr = *todel;
		*todel = (*todel)->next;
		ft_clstdelone(ptr);
	}
}