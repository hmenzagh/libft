#include	"libft.h"

char    *ft_strdup(const char *s1)
{
    int c;
    char *cp;

    c = 0; 
    while(s1[c])
        c++;
    c++;
    if (!(cp = malloc(c * sizeof(char))))
        return (NULL);
    c = 0;
    while(s1[c])
    {
        cp[c] = s1[c];
        c++;
    } 
    cp[c] = '\0';
    return (cp);
}