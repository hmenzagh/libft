/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scotch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:04:01 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/08 16:51:57 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**     _  _   ____             _    _____
**   _| || |_|  _ \ _   _  ___| | _|_   _|_ _ _ __   ___
**  |_  ..  _| | | | | | |/ __| |/ / | |/ _  |  _ \ / _ \
**  |_  ..  _| |_| | |_| | (__|   <  | | (_| | |_) |  __/
**    |_||_| |____/ \__,_|\___|_|\_\ |_|\__ _|  __/ \___|
**                                           |_|
*/

static int			check_x(const char *s)
{
	if (s[1] == 'x' || s[1] == 'X' || s[0] == ' ')
		return (1);
	return (0);
}

static void			fix_zero(t_info *chunk)
{
	char			*ptr;

	if (check_zero(chunk->finished_chunk) && chunk->precision == -1 &&
			(chunk->conversion != 'o' || !chunk->hashtag))
	{
		if (chunk->minimum_field)
		{
			ptr = ft_strchr(chunk->finished_chunk, '0');
			*ptr = ' ';
		}
		else
		{
			chunk->finished = 0;
			chunk->finished_chunk[0] = '\0';
		}
	}
}

static void			fix_ptr(t_info *chunk)
{
	if (chunk->precision && ft_strlen(chunk->finished_chunk) == 3)
	{
		--chunk->finished;
		chunk->finished_chunk[2] = '\0';
	}
}

static void			sec_fix(t_info *chunk)
{
	char			*ptr;

	ptr = ft_strchr(chunk->finished_chunk,
			(chunk->conversion == 'X') ? 'X' : 'x');
	if (ptr)
	{
		*ptr = '0';
		chunk->finished_chunk[1] = (chunk->conversion == 'X') ? 'X' : 'x';
	}
}

int					fix_stuff(t_info *chunk)
{
	char			*ptr;

	if (chunk->hashtag && !check_x(chunk->finished_chunk) && (chunk->conversion
				== 'x' || chunk->conversion == 'X' || chunk->conversion == 'p'))
		sec_fix(chunk);
	if (chunk->finished_chunk[0] == '0')
	{
		ptr = ft_strchr(chunk->finished_chunk, '-');
		if (!ptr)
			ptr = ft_strchr(chunk->finished_chunk, '+');
		if (!ptr && !chunk->negative)
			ptr = ft_strchr(chunk->finished_chunk, ' ');
		if (ptr)
		{
			chunk->finished_chunk[0] = *ptr;
			*ptr = '0';
		}
	}
	fix_zero(chunk);
	if (chunk->conversion == 'p')
		fix_ptr(chunk);
	return (0);
}
