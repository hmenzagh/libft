#include	"libft.h"

char		*ft_memsub(void *s, unsigned int start, size_t len)
{
	char			*chaine;
	char			*chaine_or;
	unsigned int	i;
	
	i = 0;
	chaine_or = (char*)s;
	if(!(chaine = malloc(len * sizeof(char))))
		return (NULL);
	while(i < len)
	{
		chaine[i] = chaine_or[i + start];
		++i;
	}
	return (chaine);
}