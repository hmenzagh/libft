#include	"libft.h"

t_clist*			ft_clstnew(void const *content, size_t content_size)
{
	t_clist		*ptr;

	if(!(ptr = malloc(sizeof(t_list))))
		return (NULL);
	if(content)
	{
		if(!(ptr->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(ptr->content, content, content_size);
	}
	else
		ptr->content = NULL;
	ptr->content_size = (content) ? content_size : 0;
	ptr->next = NULL;
	ptr->prev = NULL;
	return(ptr);
}