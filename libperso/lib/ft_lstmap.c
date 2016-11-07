#include	"libft.h"

t_list*			ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*ptr_start;
	t_list		*ptr_actual;
	t_list		*ptr_new;

	if(lst)
	{
		if(!(ptr_start = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		ptr_start = (*f)(ptr_start);
		ptr_actual = ptr_start;
		lst = lst->next;
	}
	while(lst)
	{
		if(!(ptr_new = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		ptr_new = (*f)(ptr_actual);
		ptr_actual->next = ptr_new;
		ptr_actual = ptr_new;
		lst = lst->next;
	}
	return (ptr_start);
}