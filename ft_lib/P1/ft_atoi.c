#include <stdio.h>

int     ft_atoi(const char *str)
{
    int i;
    int save;
    int res;

    i = 0;
    while(str[i] && (str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
            || str[i] == '\n' || str[i] == '\r' || str[i] == ' '))
        i++;
    if((str[i] == '+' || str[i] == '-') && str[i + 1] >= '0' && 
            str[i] <= '9')
        i++;
    save = i;
    res = 0;
    while(str[i] >= '0' && str[i] <= '9')
        res = res * 10 - (str[i++] - '0');
    if(save != 0 && str[save - 1] != '-')
        return (-res);
    return (res);
}