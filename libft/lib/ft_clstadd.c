#include	"libft.h"

void	ft_clstadd(t_clist *alst, t_clist *new)
{
	new->next = alst->next;
	new->prev = alst;
	alst->next->prev = new;
	alst->next = new;
}