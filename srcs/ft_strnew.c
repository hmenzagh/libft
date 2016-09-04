#include	"libft.h"

char		*ft_strnew(size_t size)
{
	char	*chaine;
	int		s;

	++size;
	s = size;
	if(!(chaine = malloc(size * sizeof(char))))
		return (NULL);
	while(--s >= 0)
		chaine[s] = '\0';
	return (chaine);
}