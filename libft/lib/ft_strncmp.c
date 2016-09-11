#include	"libft.h"

int		        ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t     c; 

    c = 0;
    while(s1[c] && s2[c] && c < n)
    {
        if(s1[c] != s2[c])
            return ((unsigned char)s1[c] - (unsigned char)s2[c]);
        c++;
    }
    if(c == n)
        return (0);
    return ((unsigned char)s1[c] - (unsigned char)s2[c]);	
}