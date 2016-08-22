#include <stddef.h>

void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*dst_c;
	char	*src_c;
	int		i;

	dst_c = (char*)dst;
	src_c = (char*)src;
	i = 0;

	while(i < n)
	{
		dst_c[i] = src_c[i];
		i++;
	}
	return (dst);
}