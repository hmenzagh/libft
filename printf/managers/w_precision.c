/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_precision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:46:37 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/08 16:19:03 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	n_adder(int a, int *b, int c, int *d)
{
	*b = *b + a;
	*d = *d + c;
}

static int	give_wplen(int precision, wchar_t *s)
{
	int		total;
	int		i;

	total = 0;
	i = 0;
	while (s[i] && precision)
	{
		if (s[i] <= 0x7F)
			n_adder(-1, &precision, 1, &total);
		else if (s[i] <= 0x7FF && precision >= 2)
			n_adder(-2, &precision, 2, &total);
		else if (s[i] <= 0xFFFF && precision >= 3)
			n_adder(-3, &precision, 3, &total);
		else if (s[i] <= 0x10FFFF && precision >= 4)
			n_adder(-4, &precision, 4, &total);
		++i;
	}
	return (total);
}

int			give_wimax(int precision, wchar_t *s)
{
	int		total;
	int		i;

	total = 0;
	i = 0;
	while (s[i] && precision)
	{
		if (s[i] <= 0x7F)
			n_adder(-1, &precision, 1, &total);
		else if (s[i] <= 0x7FF && precision >= 2)
			n_adder(-2, &precision, 2, &total);
		else if (s[i] <= 0xFFFF && precision >= 3)
			n_adder(-3, &precision, 3, &total);
		else if (s[i] <= 0x10FFFF && precision >= 4)
			n_adder(-4, &precision, 4, &total);
		else
			return (i);
		++i;
	}
	return (i);
}

int			ft_wstrlen(wchar_t *s)
{
	int		i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

int			give_wlength(t_info *chunk, wchar_t *s)
{
	int		total;
	int		i;

	total = 0;
	i = 0;
	if (chunk->precision)
		return (give_wplen(chunk->precision, s));
	else
	{
		while (s[i])
		{
			if (s[i] <= 0x7F)
				++total;
			else if (s[i] <= 0x7FF)
				total = total + 2;
			else if (s[i] <= 0xFFFF)
				total = total + 3;
			else
				total = total + 4;
			++i;
		}
	}
	return (total);
}
