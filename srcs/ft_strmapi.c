#include	"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ns;
	int		i;

	i = 0;
	if(!(ns = ft_strnew(ft_strlen(s))))
		return (NULL);
	while(s[i])
	{
		ns[i] = (*f)(i, s[i]);
		++i;
	}
	return (ns);
}