char        *ft_strrchr(const char *s, int c)                                                                                                            
{                                                         
    int     i;
	char	*save;                                                              

	save = 0;                                                                 
    i = 0;
    while (s[i])
		if(s[i++] == c)
			save = (char*)&s[i];
    if (s[i] == c)
        return (save);
    return (0);                                                                 
}