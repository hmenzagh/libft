#include <stddef.h>

void		*ft_memccpy(void *restrict dst, const void *restrict src, int c,
							size_t n)
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
		if(src_c[i] == c)
			return((void*)&dst_c[i + 1]);
		i++;
	}
	return (0);
}