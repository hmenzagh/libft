/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fcts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:11:38 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/08 15:50:39 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			free_all(char *format, t_list *buffer)
{
	t_list		*ptr;

	while (buffer)
	{
		ptr = buffer->next;
		if (buffer->content)
			free(buffer->content);
		if (buffer)
			free(buffer);
		buffer = ptr;
	}
	free(format);
}
