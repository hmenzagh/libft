#include	"libft.h"

char		*ft_strnew(size_t size)
{
	char	*chaine; 

	if(!(chaine = malloc(size)))
		return (NULL);
	while(--size >= 0)
		chaine[size] = '\0';
	return (chaine);
}