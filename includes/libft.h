#ifndef LIBFT_H
# define LIBFT_H

#include <stddef.h>
#include <stdlib.h>

typedef struct		s_list
{
      void			*content;
	  int			content_size;
      struct s_list	*next;
}					t_list;

void	ft_bzero(void *s, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_atoi(const char *str);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strcat(char *restrict s1, const char *restrict s2);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size);
char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strstr(const char *big, const char *little);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_strrchr(const char *s, int c); 
void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
			size_t n);

void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strclr(char *s);
void	ft_strdel(char **as);
void	ft_striter(char *s, void (*f)(char*));
void 	ft_striteri(char *s,void (*f)(unsigned int, char*));
char	*ft_strmap(char const *s,char (*f)(char));

#endif