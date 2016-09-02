#include	"libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list		*ptr;

	while(*alst)
	{
		ptr = (*alst)->next;
		(*del)(*alst, (*alst)->content_size);
		free(*alst);
		*alst = ptr;
	}
	alst = NULL;
}