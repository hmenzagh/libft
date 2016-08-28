#include	"libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*chaine; 
	unsigned int	i;
	
	i = 0;
	if(!(chaine = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while(i < len)
	{
		chaine[i] = s[i + start];
		++i;
	}
	chaine[i] = '\0';
	return (chaine);
}