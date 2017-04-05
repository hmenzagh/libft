/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 02:06:44 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/01 13:08:02 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				buff_add(int size, char *string, t_list **buffer)
{
	t_list		*ptr;
	t_list		*w_ptr;

	w_ptr = *buffer;
	if (!(ptr = ft_memalloc(sizeof(t_list))))
		return (ERROR);
	ptr->next = NULL;
	ptr->content = string;
	ptr->content_size = size;
	if (*buffer)
	{
		while (w_ptr->next)
			w_ptr = w_ptr->next;
		w_ptr->next = ptr;
	}
	else
		*buffer = ptr;
	return (1);
}
