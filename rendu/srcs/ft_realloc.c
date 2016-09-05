#include	"libft.h"

void	ft_realloc(void **data, size_t cp_len, size_t size_new)
{
	void	*ptr;

	if(!(ptr = ft_memalloc(size_new)))
		return ;
	cp_len = (cp_len < size_new) ? size_new : cp_len;
	ft_memcpy(ptr, *data, cp_len);
	free(*data);
	*data = ptr;
}