#include	"libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	(*del)(*alst, (*alst)->content_size);
	*alst = NULL;
}