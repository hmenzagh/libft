#include <stddef.h>

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	int	len;
	int j;
	int save;
	int	save_1;
	int	save_2;

	j = 0;
	while(dst[j])
		j++;
	save_1 = ft_strlen(dst);
	save_2 = ft_strlen(src);
	save = j;
	len = 0;
	while (src[len] && (len + save_1) < size - 1)
	{
		dst[j] = src[len];
		++j;
		++len;
	}
	if (j != save)
		dst[j] = '\0';
	if (save_1 > size)
		return (save_2 + size);
	return (save_1 + save_2);
}