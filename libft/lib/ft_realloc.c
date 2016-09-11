#include	"libft.h"

int		ft_realloc(void **data, size_t cp_len, size_t size_new)
{
	void	*ptr;
	if(!(ptr = malloc(size_new)))
		return (0);
	cp_len = (cp_len > size_new) ? size_new : cp_len;
	ft_memcpy(ptr, *data, cp_len);
	free(*data);
	*data = ptr;
	return (1);
}