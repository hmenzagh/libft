/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:53:49 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/07 09:17:01 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			putstr_turfu(char *src, char **dst)
{
	if (src)
		*dst = ft_strdup(src);
	else
	{
		if (!(*dst = ft_memalloc(sizeof(char) * 7)))
			return (ERROR);
		(*dst)[0] = '(';
		(*dst)[1] = 'n';
		(*dst)[2] = 'u';
		(*dst)[3] = 'l';
		(*dst)[4] = 'l';
		(*dst)[5] = ')';
	}
	return (ft_strlen(*dst));
}
