/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:50:24 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/08 15:57:53 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				manage_precision(t_info *chunk)
{
	int			len;
	int			p_len;
	int			check_neg;

	len = ft_strlen(chunk->finished_chunk);
	p_len = (chunk->precision == -1) ? 0 : chunk->precision;
	if (chunk->conversion == 's' && chunk->precision && chunk->precision < len)
		ft_bzero((void*)(chunk->finished_chunk + p_len), len - p_len);
	else if (chunk->precision > 0 && chunk->conversion != 's'
			&& chunk->conversion != 'c')
	{
		check_neg = (chunk->finished_chunk[0] == '-') ? 1 : 0;
		if (check_neg)
			chunk->finished_chunk[0] = '0';
		while (++len <= p_len)
			if (string_magic('0', &chunk->finished_chunk, START) == ERROR)
				return (ERROR);
		if (check_neg && chunk->finished_chunk[0] == '0' && len != p_len + 1)
			chunk->finished_chunk[0] = '-';
		else if (check_neg && len == p_len + 1)
			if (string_magic('-', &chunk->finished_chunk, START) == ERROR)
				return (ERROR);
	}
	return (ft_strlen(chunk->finished_chunk));
}
