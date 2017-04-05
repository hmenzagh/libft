/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:12:57 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/07 00:44:55 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				manage_padding(t_info *chunk)
{
	int			i;
	char		c;
	int			len;
	int			type;

	i = 0;
	c = (chunk->zero_pad) ? '0' : ' ';
	len = ft_strlen(chunk->finished_chunk);
	len = (len == 0 && chunk->conversion == 'c') ? 1 : len;
	type = (chunk->negative) ? END : START;
	while (i + len < chunk->minimum_field)
	{
		if (string_magic(c, &chunk->finished_chunk, type) == ERROR)
			return (ERROR);
		++i;
	}
	return (ft_strlen(chunk->finished_chunk));
}
