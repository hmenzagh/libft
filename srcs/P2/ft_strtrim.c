#include	"libft.h"

char		*ft_strtrim(char const *s)
{
	char	*chaine;
	int		off;
	int		end;
	int		i;

	off = 0;
	end = ft_strlen(s) - 1;
	i = 0;
	while(s[off] && (s[off] == ' ' || s[off] == '\t' || s[off] == '\n'))
		++off;
	while(s[end] && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n'))
		--end;
	if(!(chaine = malloc(sizeof(char) * (end - off + 2))))
		return (NULL);
	while(i < end - off + 2)
	{
		chaine[i] = s[off + i];
		i++;
	}
	chaine[i] = '\0';
	return (chaine);
}