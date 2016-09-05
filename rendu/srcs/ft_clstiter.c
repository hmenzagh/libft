#include	"libft.h"

void	ft_clstiter(t_clist *lst, void (*f)(t_clist *elem))
{
	ft_findclstr(&lst);
	lst = lst->next;
	while(!ft_isclstr(lst))
	{
		(*f)(lst);
		lst = lst->next;
	}
}