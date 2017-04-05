/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:30:55 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/08 17:13:22 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		sec_printf(va_list *args, t_list **buffer, t_info *chunk,
		char *format_editable)
{
	int			status;

	status = 0;
	while (42)
	{
		if ((get_next_chunk(format_editable, &status, chunk)) == ERROR)
			return (ERROR);
		if (!chunk->finished && status >= 0)
			if ((genit(chunk, args)) == ERROR)
				return (ERROR);
		if (status > 0)
			buff_add(chunk->finished, chunk->finished_chunk, buffer);
		if (status <= 0)
			break ;
		ft_bzero(chunk, sizeof(t_info));
		chunk->finished_chunk = NULL;
	}
	return (status);
}

int				ft_printf(const char *format, ...)
{
	va_list		args;
	t_list		*buffer;
	t_info		chunk;
	char		*format_editable;
	int			status;

	status = 0;
	buffer = NULL;
	format_editable = ft_strdup(format);
	ft_bzero(&chunk, sizeof(t_info));
	va_start(args, format);
	status = sec_printf(&args, &buffer, &chunk, format_editable);
	if (status == OVER)
		status = custom_putstr(buffer);
	else
	{
		free_all(format_editable, buffer);
		return (ERROR);
	}
	free_all(format_editable, buffer);
	va_end(args);
	return (status);
}
