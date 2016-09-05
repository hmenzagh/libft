#include	"libft.h"

void		ft_clstaddend(t_clist **alst, t_clist *new)
{
	ft_findclstr(alst);
	new->next = (*alst);
	new->prev = (*alst)->prev;
	(*alst)->prev->next = new;
	(*alst)->prev = new;
}