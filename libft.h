/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:50:19 by hmenzagh          #+#    #+#             */
/*   Updated: 2017/04/05 12:14:01 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define SPACE_CHECK cpv[1]
# define LEN_S cpv[2]
# define SAVE_S cpv[3]
# define N_WORDS_S cpv[0]
# define ERROR -1
# define OK 0
# define KO -1
# define LFD content_size
# define LBF content
# define OVER -42
# define CONTINUE -4242
# define BUFF_SIZE 128


# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct	s_list
{
	void			*content;
	int				content_size;
	struct s_list	*next;
}				t_list;

int				get_next_line(int const fd, char **line);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putnbr(int n);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_bzero(void *s, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *restrict dst, const void *restrict src,
							int c, size_t n);
void			*ft_memcpy(void *restrict dst, const void *restrict src,
							size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s1);
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			ft_putendl(char const *s);
void			ft_putstr(char const *s);
int				ft_strequ(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strcat(char *restrict s1, const char *restrict s2);
char			*ft_strcpy(char *dest, const char *src);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
size_t			ft_strlcat(char *restrict dst, const char *restrict src,
							size_t size);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *restrict s1, const char *restrict s2,
							size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *big, const char *little);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_realloc(void **data, size_t cp_len, size_t size_new);
void			ft_lstaddend(t_list **alst, t_list *new);
int				ft_countiter(char *s, char c);
int				ft_lstsize(t_list *ptr);
t_list			*ft_lstat(t_list *ptr, int pos);
int				ft_lstfreeone(t_list **o_ptr, t_list *d_ptr);
void			ft_putwchar(wchar_t chr);
void			ft_putwstr(wchar_t const *str);
void			ft_error(char *error_message, int error_code);


#endif
