/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:24:40 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/11/07 14:02:49 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstsize(t_list *ptr)
{
	int		count;

	count = 0;
	while (ptr)
	{
		++count;
		ptr = ptr->next;
	}
	return (count);
}