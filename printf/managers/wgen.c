/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wgen.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:35:25 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/08 12:22:47 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				wgen(t_info *chunk, va_list *args)
{
	int			check;

	if (chunk->conversion == 'c')
		check = w_char(chunk, va_arg(*args, wchar_t));
	else
		check = w_chain(chunk, va_arg(*args, wchar_t*));
	if (check == ERROR)
		return (ERROR);
	if ((check = manage_precision(chunk)) != ERROR)
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
