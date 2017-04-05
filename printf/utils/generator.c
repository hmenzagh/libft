/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 20:30:13 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/08 15:53:19 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	gen_signed(t_info *chunk, va_list *args, t_psf *db)
{
	intmax_t	var;
	int			check;

	var = db->psf_s[chunk->len_modifier](args);
	if ((check = putnbr_turfu_signed(var, &chunk->finished_chunk)) != ERROR)
		if ((check = manage_precision(chunk)) != ERROR)
			if ((check = manage_prefix(chunk)) != ERROR)
				check = manage_padding(chunk);
	if (check == ERROR)
		return (ERROR);
	fix_stuff(chunk);
	chunk->finished = ft_strlen(chunk->finished_chunk);
	return (1);
}

static int	gen_unsigned(t_info *chunk, va_list *args, t_psf *db)
{
	uintmax_t	var;
	int			check;

	var = db->psf_u[chunk->len_modifier](args);
	if ((check = putnbr_turfu_unsigned(var, &chunk->finished_chunk,
					chunk->conversion)) != ERROR)
		if ((check = manage_precision(chunk)) != ERROR)
			if ((check = manage_hashtag(chunk)) != ERROR)
				check = manage_padding(chunk);
	if (check == ERROR)
		return (ERROR);
	fix_stuff(chunk);
	chunk->finished = ft_strlen(chunk->finished_chunk);
	return (1);
}

static int	gen_chars(t_info *chunk, va_list *args)
{
	int		check;

	if (chunk->conversion == 'c')
		check = string_magic((char)va_arg(*args, int),
						&chunk->finished_chunk, START);
	else if (chunk->conversion == '%')
		check = string_magic('%', &chunk->finished_chunk, START);
	else
		check = putstr_turfu(va_arg(*args, char*), &(chunk->finished_chunk));
	if (check == ERROR)
		return (ERROR);
	if (chunk->conversion != '%')
		check = manage_precision(chunk);
	if (check != ERROR)
		check = manage_padding(chunk);
	if (check == ERROR)
		return (ERROR);
	chunk->finished = ft_strlen(chunk->finished_chunk);
	chunk->finished = (chunk->conversion == 'c' && chunk->finished == 0)
		? 1 : chunk->finished;
	chunk->finished = (chunk->minimum_field && chunk->finished <
			chunk->minimum_field) ? chunk->minimum_field : chunk->finished;
	return (1);
}

static int	gen_ptrs(t_info *chunk, va_list *args)
{
	long	ptr;
	int		check;

	ptr = va_arg(*args, long);
	if ((check = putnbr_turfu_unsigned((uintmax_t)ptr,
					&chunk->finished_chunk, chunk->conversion)) != ERROR)
		if ((check = manage_precision(chunk)) != ERROR)
			if ((check = manage_hashtag(chunk)) != ERROR)
				check = manage_padding(chunk);
	if (check == ERROR)
		return (ERROR);
	fix_stuff(chunk);
	chunk->finished = ft_strlen(chunk->finished_chunk);
	return (1);
}

int			genit(t_info *chunk, va_list *args)
{
	int		ret;
	t_psf	db;
	char	c;

	psf_init(&db);
	c = chunk->conversion;
	if (chunk->len_modifier == 4 && (c == 'c' || c == 's'))
		ret = wgen(chunk, args);
	else if (check_signed(chunk->conversion))
		ret = gen_signed(chunk, args, &db);
	else if (c == 'p')
		ret = gen_ptrs(chunk, args);
	else if (c == 's' || c == 'c' || c == '%')
		ret = gen_chars(chunk, args);
	else
		ret = gen_unsigned(chunk, args, &db);
	return (ret);
}
