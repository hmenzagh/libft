/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:55:31 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/08 16:47:41 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <inttypes.h>
# include "libft.h"
# define ERROR -1
# define OVER  -42
# define START 1
# define END 0
# define REPLACE 2
# define HEXAMAJ 4
# define HEXA 3
# define OCTAL 2
# define DECIMAL 1
# define SIGNED 1
# define UNSIGNED 0

/*
**    Length modifiers ID'S :
**    hh  -----> 1
**    h   -----> 2
**    ll  -----> 3
**    l   -----> 4
**    j   -----> 5
**    z   -----> 6
*/
typedef struct	s_info
{
	int				finished;
	int				zero_pad;
	int				negative;
	int				positive;
	int				space;
	int				hashtag;
	int				minimum_field;
	int				precision;
	int				len_modifier;
	char			conversion;
	char			*finished_chunk;
}				t_info;

typedef struct	s_psf
{
	intmax_t	(*psf_s[7])(va_list*);
	uintmax_t	(*psf_u[7])(va_list*);
}				t_psf;

int				ft_printf(const char *format, ...);
int				get_next_chunk(char *format, int *read_pos, t_info *chunk);
int				genit(t_info *chunk, va_list *args);
int				custom_putstr(t_list *ptr);
int				initial_flags(char *format, int *pos, t_info *chunk);
int				conversion_flags(char *format, int *pos, t_info *chunk);
int				precision(char *format, int *pos, t_info *chunk);
int				check_zero(const char *s);
int				len_modifiers(char *format, int *pos, t_info *chunk);
int				minimum_field(char *format, int *pos, t_info *chunk);
int				initial_flags_detect(char c);
int				precision_detect(char c);
int				len_modifiers_detect(char c);
int				conversion_flags_detect(char c);
int				validity_check(char c);
int				buff_add(int size, char *string, t_list **buffer);
void			free_all(char *format, t_list *buffer);
void			normalise_chunk(t_info *chunk);
int				string_magic(char c, char **s, int start);
int				putnbr_turfu_signed(intmax_t n, char **s);
int				putnbr_turfu_unsigned(uintmax_t n, char **s, char type);
int				putchar_turfu(char **s, char c);
int				putstr_turfu(char *src, char **dst);
int				manage_precision(t_info *chunk);
int				manage_hashtag(t_info *chunk);
int				manage_prefix(t_info *chunk);
int				manage_padding(t_info *chunk);
int				check_signed(char c);
void			psf_init(t_psf *db);
intmax_t		load_i(va_list *args);
intmax_t		load_l(va_list *args);
intmax_t		load_ll(va_list *args);
intmax_t		load_short(va_list *args);
intmax_t		load_s_char(va_list *args);
intmax_t		load_imax(va_list *args);
intmax_t		load_sst(va_list *args);
uintmax_t		load_ul(va_list *args);
uintmax_t		load_ull(va_list *args);
uintmax_t		load_ushort(va_list *args);
uintmax_t		load_u_char(va_list *args);
uintmax_t		load_uimax(va_list *args);
uintmax_t		load_st(va_list *args);
uintmax_t		load_ui(va_list *args);
int				fix_stuff(t_info *chunk);
int				give_wlength(t_info *chunk, wchar_t *s);
int				give_wimax(int precision, wchar_t *s);
int				ft_wstrlen(wchar_t *s);
int				wgen(t_info *chunk, va_list *args);
int				w_chain(t_info *chunk, wchar_t *s);
int				w_char(t_info *chunk, wchar_t c);

#endif
