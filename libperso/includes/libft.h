#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

/* --- Struct Lst Chaine Simple ---------------- */
typedef struct		s_list
{
	void			*content;
	int				content_size;
	struct	s_list	*next;
}					t_list;

/* - Struct Lst Doublement Chaines Circulaires - */
typedef struct		s_clist
{
	void			*content;
	int				content_size;
	struct	s_clist	*prev;
	struct	s_clist	*next;
}					t_clist;

/* ~~~ Gestion de Nombres ~~~~~~~~~~~~~~~~~~~~~~ */
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putnbr(int n);

/* ~~~ Listes Chaines Simples ~~~~~~~~~~~~~~~~~~ */
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstaddend(t_list **alst, t_list *new);
void	ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list*	ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list*	ft_lstnew(void const *content, size_t content_size);

/* ~~~ Listes Doublement Chaines Circulaires ~~~ */
void	ft_clstadd(t_clist *alst, t_clist *new);
void	ft_clstaddend(t_clist **alst, t_clist *new);
void	ft_clstaddfront(t_clist **alst, t_clist *new);
void	ft_clstdel(t_clist **todel);
void	ft_clstdelone(t_clist **todel);
void	ft_clstiter(t_clist *lst, void (*f)(t_clist *elem));
t_clist	*ft_clstnew(void const *content, size_t content_size);
t_clist	*ft_clstnew_racine(void);
void	ft_findclstr(t_clist **lst);
int		ft_isclstr(t_clist *lst);

/* ~~~ Gestion Memoire ~~~~~~~~~~~~~~~~~~~~~~~~~ */
void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
					size_t n);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_memdel(void **ap);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
int		ft_realloc(void **data, size_t cp_len, size_t size_new);
int		ft_memchc(void *s, char c, int len);
void	ft_memcat(void *s1, void *s2, int start, int end);
int		ft_memrealloccp(void **dst, void *src, size_t len_tot, size_t len_cp);
int		ft_memreallocsub(void **s, unsigned int start, size_t len);
char	*ft_memsub(void *s, unsigned int start, size_t len);

/* ~~~ Gestion de Strings ~~~~~~~~~~~~~~~~~~~~~~ */
		/* --- Operations --- */
void	ft_strclr(char *s);
void	ft_strdel(char **as);
char	*ft_strdup(const char *s1);
char	*ft_strnew(size_t size);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
		/* --- Affichage --- */
void	ft_putendl(char const *s);
void	ft_putstr(char const *s);
		/* --- Analyse ----- */
int		ft_strequ(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strrchr(const char *s, int c); 
		/* -- Manipulation - */
char	*ft_strcat(char *restrict s1, const char *restrict s2);
char	*ft_strcpy(char *dest, const char *src);
void	ft_striter(char *s, void (*f)(char*));
void 	ft_striteri(char *s,void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size);
char	*ft_strmap(char const *s,char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	**ft_strsplit(char const *s, char c);
char	*ft_strstr(const char *big, const char *little);

/* ~~~ Gestion Caracteres ~~~~~~~~~~~~~~~~~~~~~~ */
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c); 
int		ft_isdigit(int c);
int		ft_isprint(int c);

/* ~~~ File Descriptor ~~~~~~~~~~~~~~~~~~~~~~~~~ */
void	ft_putchar_fd(char c,int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char const *s,int fd);

/* ~~~ Defines ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
# define 	SPACE_CHECK cpv[1]
# define 	LEN_S cpv[2]
# define 	SAVE_S cpv[3]
# define 	N_WORDS_S cpv[0]

#endif
