#include	"libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		cpv[4];
	char	**tab;

	len_s = 0;
	space_check_s = 1;
	n_words_s = 0;
	while(s[len_s])
	{
		n_words_s = (s[len_s] != c && space_check) ? n_words_s + 1 : n_words_s;
		space_check = ((s[len_s++] == c) ? 1 : 0);	
	}
	if(!(tab = malloc (sizeof(char*) * (n_words_s + 1))))
		return (NULL);
	tab[n_words_s] = NULL;
	while (len_s-- >= 0)
	{
		if(s[len_s] != c)
		{
			save_s = len_s;
			while(s[len_s] != c && len_s != -1)
				--len_s;
			tab[--n_words_s] = ft_strsub(s, len_s + 1, save_s - len_s);
		}
	}
	return (tab);
}