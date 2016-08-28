#include	"libft.h"
#define 	n_words cpv[0]
#define 	space_check cpv[1]
#define 	len cpv[2]
#define 	save cpv[3]

char		**ft_strsplit(char const *s, char c)
{
	int		cpv[4];
	char	**tab;

	len = 0;
	space_check = 1;
	n_words = 0;
	while(s[len])
	{
		n_words = ((s[len] != c && space_check) ? n_words + 1 : n_words);
		space_check = ((s[len++] == c) ? 1 : 0);	
	}
	if(!(tab = malloc (sizeof(char*) * (n_words + 1))))
		return (NULL);
	tab[n_words] = NULL;
	while (len-- >= 0)
	{
		if(s[len] != c)
		{
			save = len;
			while(s[len] != c && len != -1)
				--len;
			tab[--n_words] = ft_strsub(s, len + 1, save - len);
		}
	}
	return (tab);
}