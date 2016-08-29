#include	"libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int     c; 

    c = 0;
    while(s1[c] && s2[c] && c < n - 1)
    {
        if(s1[c] != s2[c])
            return (s1[c] - s2[c]);
        c++;
    }
    return (s1[c] - s2[c]);	
}