#include <stddef.h>

void		*ft_memchr(const void *s, int c, size_t n)
{
	int     i;
	char	*s_c;

	s_c = (char*)s;
    i = 0;
    while (i < n && s_c[i] != c)
        ++i;
    if (s_c[i] == c)
        return ((void*)&s_c[i]);
    return (0);
}