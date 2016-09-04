int         ft_strcmp(const char *s1, const char *s2)
{
    int     c; 

    c = 0;
    while(s1[c] && s2[c])
    {
        if(s1[c] != s2[c])
            return ((unsigned char)s1[c] - (unsigned char)s2[c]);
        c++;
    }
    return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}