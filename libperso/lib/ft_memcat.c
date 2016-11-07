#include	"libft.h"

void		ft_memcat(void *s1, void *s2, int start, int len)
{
	char	*s1_c;
	char	*s2_c;
	int		i;

	s1_c = (char*)s1;
	s2_c = (char*)s2;
	i = 0;
	while(i < len)
		s1_c[start++] = s2_c[i++];
}