#include	"libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_c;
	char	*src_c;
	char	*tmp;
	size_t	i;

	dst_c = (char*)dst;
	src_c = (char*)src;
	i = -1;
	if(!(tmp = malloc(len + 1)))
		return (dst);
	while(++i < len)
		tmp[i] = src_c[i];
	i = -1;
	while(++i < len)
		dst_c[i] = tmp[i];
	free(tmp);
	return(dst);
}