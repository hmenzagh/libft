#include	"libft.h"

char		*ft_itoa(int n)
{
	int		c_s;
	int		save;
	long	utils;
	char	*chaine;

	c_s = 0;
	save = n;
	utils = n;
	utils = (utils < 0) ? -utils : utils;
	while(save && ++c_s)
		save /= 10;
	c_s = (n <= 0) ? c_s + 1 : c_s;
	if(!(chaine = malloc(sizeof(char) * (c_s + 1))))
		return (NULL);
	chaine[c_s--] = '\0';
	if(n == 0)
		chaine[0] = '0';
	if(n < 0)
		chaine[0] = '-';
	while(utils)
	{
		chaine[c_s--] = '0' + utils % 10;
		utils /= 10;
	}
	return(chaine);
}