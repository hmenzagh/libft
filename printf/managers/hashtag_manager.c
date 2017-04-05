/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtag_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:48:03 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/07 09:51:49 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		manage_hashtag_o(t_info *chunk)
{
	if (chunk->finished_chunk[0] != '0')
		if (string_magic('0', &chunk->finished_chunk, START) == ERROR)
			return (ERROR);
	return (1);
}

static int		manage_hashtag_x(t_info *chunk)
{
	int			check;
	int			i;
	char		c;

	i = 0;
	check = 0;
	c = (chunk->conversion == 'x' || chunk->conversion == 'p') ? 'x' : 'X';
	while (chunk->finished_chunk[i])
	{
		if (chunk->finished_chunk[i] != '0')
		{
			++check;
			break ;
		}
		++i;
	}
	if (check || chunk->conversion == 'p')
	{
		if (string_magic(c, &chunk->finished_chunk, START) == ERROR ||
				string_magic('0', &chunk->finished_chunk, START) == ERROR)
			return (ERROR);
	}
	return (1);
}

int				manage_hashtag(t_info *chunk)
{
	if (!chunk->hashtag)
		return (0);
	if (chunk->conversion == 'o')
	{
		if (manage_hashtag_o(chunk) == ERROR)
			return (ERROR);
	}
	else
	{
		if (manage_hashtag_x(chunk) == ERROR)
			return (ERROR);
	}
	return (ft_strlen(chunk->finished_chunk));
}
