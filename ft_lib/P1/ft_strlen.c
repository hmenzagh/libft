int     ft_strlen(const char *s)
{
    int c; 

    c = 0; 
    while(s[c])
        c++;
    return (c);
}