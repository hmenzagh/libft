#include	"libft.h"

void		ft_findclstr(t_clist **lst)
{
	while(!ft_isclstr(*lst))
		*lst = (*lst)->next;
}