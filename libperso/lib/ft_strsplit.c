#include	"libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		cpv[4];
	char	**tab;
	
	LEN_S = 0;
	SPACE_CHECK = 1;
	N_WORDS_S = 0;
	while(s[LEN_S])
	{
		N_WORDS_S = (s[LEN_S] != c && SPACE_CHECK) ? N_WORDS_S + 1 : N_WORDS_S;
		SPACE_CHECK = ((s[LEN_S++] == c) ? 1 : 0);	
	}
	if(!(tab = malloc (sizeof(char*) * (N_WORDS_S + 1))))
		return (NULL);
	tab[N_WORDS_S] = NULL;
	while (LEN_S-- >= 0)
	{
		if(s[LEN_S] != c)
		{
			SAVE_S = LEN_S;
			while(s[LEN_S] != c && LEN_S != -1)
				--LEN_S;
			tab[--N_WORDS_S] = ft_strsub(s, LEN_S + 1, SAVE_S - LEN_S);
		}
	}
	return (tab);
}