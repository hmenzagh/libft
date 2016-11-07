char        *ft_strstr(const char *big, const char *little)
{
    int     c;
    int     i;

    c = 0;
    i = 0;
    if(!*little)
        return ((char*)big);
    while (big[c])
    {
        i = 0;
        while(big[c + i] == little[i])
            if(little[1 + i++] == '\0')
                return ((char*)&big[c]);
        c++;
    }
    return (0);
}