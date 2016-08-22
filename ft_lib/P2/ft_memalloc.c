#include	"libft.h"

void*		ft_memalloc(size_t size)
{
	void	*ptr;

	if(!(ptr = malloc(size)))
		return (NULL);
	return(ft_bzero(ptr, size));
}