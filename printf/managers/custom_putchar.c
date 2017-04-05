/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_putchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:35:44 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/08 15:57:06 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			putchar_turfu(char **s, char c)
{
	if (!(*s = ft_memalloc(sizeof(char) * 2)))
		return (ERROR);
	*s[0] = c;
	return (1);
}
