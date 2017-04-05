/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:52:28 by hmenzagh          #+#    #+#             */
/*   Updated: 2017/04/05 11:46:09 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*ptr;

	ptr = memalloc(sizeof(t_list));
	if (content)
	{
		ptr->content = memalloc(content_size);
		ft_memcpy(ptr->content, content, content_size);
	}
	else
		ptr->content = NULL;
	ptr->content_size = (content) ? content_size : 0;
	ptr->next = NULL;
	return (ptr);
}
