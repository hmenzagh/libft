#include	"libft.h"

void		ft_clstaddfront(t_clist **alst, t_clist *new)
{
	ft_findclstr(alst);
	new->next = (*alst)->next;
	new->prev = (*alst);
	(*alst)->next->prev = new;
	(*alst)->next = new;
}