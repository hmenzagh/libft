/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 01:49:51 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/06 01:50:55 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

void	ft_putwstr(wchar_t const *str)
{
	while (*str)
	{
		ft_putwchar(*str);
		++str;
	}
}
