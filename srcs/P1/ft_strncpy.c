#include	"libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	int		i; 

	i = 0; 
	while(i < len)
	{
		if(src[i])
			dst[i] = src[i];
		else
			dst[i] = '\0';
		++i;
	}
	return (dst);
}