#include	"libft.h"

char		*ft_strmap(char const *s,char (*f)(char))
{
	char	*ns;
	int		i;

	i = 0;
	if(!(ns = ft_memalloc(ft_strlen(s))))
		return (NULL);
	while(s[i])
	{
		ns[i] = (*f)(s[i]);
		++i;
	}
	return (ns);
}