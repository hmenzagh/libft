#include <stddef.h>

void		*ft_memset(void *b, int c, size_t len)
{
    char    *conv;

    conv = (char*)b;
    while(len-- > 0)
        *conv++ = c;
    return (b);
}