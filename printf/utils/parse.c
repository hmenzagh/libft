/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:14:10 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/08 14:28:24 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		process_string(char *format, int pos, t_info *chunk)
{
	int			w_pos;
	int			cp_len;

	w_pos = pos;
	while (format[w_pos] && format[w_pos] != '%')
		++w_pos;
	cp_len = w_pos - pos;
	chunk->finished = cp_len;
	if (!(chunk->finished_chunk = ft_memalloc(sizeof(char) * (cp_len + 1))))
		return (ERROR);
	ft_strncpy(chunk->finished_chunk, format + pos, cp_len);
	return (w_pos);
}

static int		process_flags(char *format, int pos, t_info *chunk)
{
	int			check;

	check = 0;
	++pos;
	if ((check = initial_flags(format, &pos, chunk)) != ERROR)
		if ((check = minimum_field(format, &pos, chunk)) != ERROR)
			if ((check = precision(format, &pos, chunk)) != ERROR)
				if ((check = len_modifiers(format, &pos, chunk)) != ERROR)
					check = conversion_flags(format, &pos, chunk);
	if (check == ERROR)
		return (ERROR);
	if (check == OVER)
		return (OVER);
	return (pos);
}

int				get_next_chunk(char *format, int *pos, t_info *chunk)
{
	if (format[*pos])
	{
		if (format[*pos] != '%')
			*pos = process_string(format, *pos, chunk);
		else
			*pos = process_flags(format, *pos, chunk);
	}
	else
		*pos = OVER;
	normalise_chunk(chunk);
	return (*pos);
}
