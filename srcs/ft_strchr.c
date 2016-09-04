char        *ft_strchr(const char *s, int c)
{
    int     i;

    i = 0;
    while (s[i] && s[i] != c)
        ++i;
    if (c == '\0' || s[i] == c)
        return ((char*)&s[i]);
    return (0);
}