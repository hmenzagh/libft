/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:05:07 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/01 13:18:38 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				manage_prefix(t_info *chunk)
{
	int			check;
	int			i;
	char		c;

	check = 0;
	i = 0;
	if (!chunk->positive && !chunk->space)
		return (0);
	c = (chunk->positive) ? '+' : ' ';
	while (chunk->finished_chunk[i])
	{
		if (chunk->finished_chunk[i] == '-')
			check = 1;
		++i;
	}
	if (!check)
		if (string_magic(c, &chunk->finished_chunk, START) == ERROR)
			return (ERROR);
	return (ft_strlen(chunk->finished_chunk));
}
