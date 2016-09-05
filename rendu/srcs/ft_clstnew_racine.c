#include	"libft.h"

t_clist*		ft_clstnew_racine(void)
{
	t_clist		*ptr;

	if(!(ptr = malloc(sizeof(t_list))))
		return (NULL);
	ptr->content_size = 101;
	ptr->content = (void*)&(ptr->content_size);
	ptr->next = ptr;
	ptr->prev = ptr;
	return(ptr);
}