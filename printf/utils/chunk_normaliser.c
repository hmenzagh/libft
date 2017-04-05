/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_normaliser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 19:16:22 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/08 12:10:09 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_num_conversion(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

static int		check_hastag(char c)
{
	if (c == 'c' || c == 'd' || c == 'i' || c == 'p' || c == 's' || c == 'u')
		return (1);
	return (0);
}

int				check_signed(char c)
{
	if (c == 'd' || c == 'i')
		return (1);
	return (0);
}

static void		normalise_conversion(t_info *chunk)
{
	char		c;

	c = chunk->conversion;
	if (c == 'S' || c == 'D' || c == 'O' || c == 'U' || c == 'C')
	{
		chunk->conversion = c + 32;
		chunk->len_modifier = 4;
	}
}

void			normalise_chunk(t_info *chunk)
{
	normalise_conversion(chunk);
	if (chunk->zero_pad && (chunk->negative || (chunk->precision &&
			check_num_conversion(chunk->conversion))))
		chunk->zero_pad = 0;
	if (chunk->space && (chunk->positive || !check_signed(chunk->conversion)))
		chunk->space = 0;
	if (chunk->hashtag && check_hastag(chunk->conversion))
		chunk->hashtag = 0;
	if (chunk->positive && !check_signed(chunk->conversion))
		chunk->positive = 0;
	if (chunk->conversion == 'p')
		chunk->hashtag = 1;
}
