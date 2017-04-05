/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:59:16 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/01 16:55:34 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		give_char(int n)
{
	if (n < 0)
		n = -n;
	return (n + '0');
}

int				putnbr_turfu_signed(intmax_t n, char **s)
{
	int			check;

	check = (n < 0) ? 1 : 0;
	if (n == 0)
		if (string_magic('0', s, START) == ERROR)
			return (ERROR);
	while (n)
	{
		if (string_magic(give_char(n % 10), s, START) == ERROR)
			return (ERROR);
		n = n / 10;
	}
	if (check)
		if (string_magic('-', s, START) == ERROR)
			return (ERROR);
	return (ft_strlen(*s));
}
