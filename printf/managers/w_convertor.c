/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_convertor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:57:12 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/08 16:19:19 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			wchar_convert(char *wchar, wchar_t chr)
{
	if (chr <= 0x7F)
		wchar[0] = (chr);
	else if (chr <= 0x7FF)
	{
		wchar[0] = ((chr >> 6) + 0xC0);
		wchar[1] = ((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0xFFFF)
	{
		wchar[0] = ((chr >> 12) + 0xE0);
		wchar[1] = (((chr >> 6) & 0x3F) + 0x80);
		wchar[2] = ((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0x10FFFF)
	{
		wchar[0] = ((chr >> 18) + 0xF0);
		wchar[1] = (((chr >> 12) & 0x3F) + 0x80);
		wchar[2] = (((chr >> 6) & 0x3F) + 0x80);
		wchar[3] = ((chr & 0x3F) + 0x80);
	}
}

static void			cp_conversion(char *wchar, char *buff, wchar_t *s, int len)
{
	int				i;
	int				y;
	int				z;

	y = 0;
	i = 0;
	z = 0;
	while (z < len)
	{
		wchar_convert(wchar, s[z]);
		while (wchar[y] && y < 4)
		{
			buff[i] = wchar[y];
			i++;
			y++;
		}
		y = 0;
		++z;
		ft_bzero(wchar, 4);
	}
}

int					w_chain(t_info *chunk, wchar_t *s)
{
	int				ncpchar;
	int				precision;
	int				i;
	char			*wchar;

	if (!s)
	{
		if (!(chunk->finished_chunk = ft_memalloc(7)))
			return (ERROR);
		ft_strcpy(chunk->finished_chunk, "(null)");
		return (1);
	}
	precision = (chunk->precision == -1) ? 0 : chunk->precision;
	ncpchar = (chunk->precision) ? give_wimax(precision, s) : ft_wstrlen(s);
	i = 0;
	if (!(chunk->finished_chunk = ft_memalloc(give_wlength(chunk, s) + 1)))
		return (ERROR);
	if (!(wchar = ft_memalloc(5)))
		return (ERROR);
	cp_conversion(wchar, chunk->finished_chunk, s, ncpchar);
	free(wchar);
	return (1);
}

int					w_char(t_info *chunk, wchar_t c)
{
	char			*wchar;
	int				i;

	i = 0;
	if (!(wchar = ft_memalloc(4)))
		return (ERROR);
	wchar_convert(wchar, c);
	if (!(chunk->finished_chunk = ft_memalloc(ft_strlen(wchar) + 1)))
		return (ERROR);
	while (wchar[i])
	{
		chunk->finished_chunk[i] = wchar[i];
		++i;
	}
	free(wchar);
	return (1);
}
