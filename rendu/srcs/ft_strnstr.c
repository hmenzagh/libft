#include	"libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t  c;
    int     i;

    c = 0;
    i = 0;
    if(!*little)
        return ((char*)big);
    while (big[c] && c < len)
    {
        i = 0;
        while(big[c + i] == little[i] && c + i < len)
            if(little[1 + i++] == '\0')
                return ((char*)&big[c]);
        c++;
    }
    return (0);
}