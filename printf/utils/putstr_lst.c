/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 20:08:54 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/08 15:50:58 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				custom_putstr(t_list *ptr)
{
	int			i;
	int			total;

	i = 0;
	total = 0;
	while (ptr)
	{
		total += ptr->content_size;
		if (ptr->content_size >= 0)
			while (i < ptr->content_size)
				ft_putchar(((char*)ptr->content)[i++]);
		i = 0;
		ptr = ptr->next;
	}
	return (total);
}
