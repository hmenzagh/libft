#include	"libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		y;
	char	*chaine;

	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	y = 0;
	if(!(chaine = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while(s1[y])
		chaine[i++] = s1[y++];
	y = 0;
	while(s2[y])
		chaine[i++] = s1[y];
	chaine[i] = '\0';
	return (chaine);
}