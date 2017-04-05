/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:50:04 by hmenzagh          #+#    #+#             */
/*   Updated: 2017/04/05 11:41:37 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_realloc(void **data, size_t cp_len, size_t size_new)
{
	void	*ptr;

	ptr = ft_memalloc(size_new);
	cp_len = (cp_len > size_new) ? size_new : cp_len;
	ft_memcpy(ptr, *data, cp_len);
	free(*data);
	*data = ptr;
}
