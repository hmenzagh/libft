/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:18:43 by hmenzagh          #+#    #+#             */
/*   Updated: 2017/04/05 12:17:04 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_c;
	char	*src_c;
	char	*tmp;
	size_t	i;

	dst_c = (char*)dst;
	src_c = (char*)src;
	i = -1;
	tmp = ft_memalloc(len + 1);
	while (++i < len)
		tmp[i] = src_c[i];
	i = -1;
	while (++i < len)
		dst_c[i] = tmp[i];
	free(tmp);
	return (dst);
}
