#include	"libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		c;
	char	*s1_c;
	char	*s2_c;

	s1_c = (char*)s1;
	s2_c = (char*)s2;

	c = 0;
	while(c < n)
	{
		if(s1_c[c] != s2_c[c])
			return (s1_c[c] - s2_c[c]);
		++c;
	}
	return (0);
}