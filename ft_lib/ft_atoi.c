#include <stdio.h>

int     spaces_count(const char *str)
{
    int off;

    off = 0; 
    while(str[off] && (str[off] == '\t' || str[off] == '\v' || str[off] == '\f'
            || str[off] == '\n' || str[off] == '\r' || str[off] == ' '))
        off++;
    if((str[off] == '+' || str[off] == '-') && str[off + 1] >= '0' && 
            str[off] <= '9')
        off++;
    return (off);    
}

int     ft_atoi(const char *str)
{
    int i;
    int save;
    int res;

    i = spaces_count(str);
    save = i;
    res = 0;
    while(str[i] >= '0' && str[i] <= '9')
        res = res * 10 - (str[i++] - '0');
    if(save != 0 && str[save - 1] != '-')
        return (-res);
    return (res);
}