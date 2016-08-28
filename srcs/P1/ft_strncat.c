#include <stddef.h>

char		*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
    int     c;
    int     i;

    c = 0;
    i = 0;
    while (s1[c])
        ++c;
    while (i < n && s2[i])
    {
        s1[c + i] = s2[i];
        ++i;
    }
	s1[c + i] = '\0';
    return (s1);
}