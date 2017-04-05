/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:59:16 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/08 15:57:25 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		give_char(int n, char type)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	return ((type == 'X') ? n - 10 + 'A' : n - 10 + 'a');
}

static int		give_base(char type)
{
	if (type == 'x' || type == 'X' || type == 'p')
		return (16);
	else if (type == 'o')
		return (8);
	else
		return (10);
}

int				putnbr_turfu_unsigned(uintmax_t n, char **s, char type)
{
	int			base;

	base = give_base(type);
	if (n == 0)
		if (string_magic('0', s, START) == ERROR)
			return (ERROR);
	while (n)
	{
		if (string_magic(give_char(n % base, type), s, START) == ERROR)
			return (ERROR);
		n = n / base;
	}
	return (ft_strlen(*s));
}
