/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_detectors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:10:01 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/05 23:41:54 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			initial_flags_detect(char c)
{
	if (c == '#' || c == '0' || c == ' ' || c == '-' || c == '+')
		return (1);
	return (0);
}

int			precision_detect(char c)
{
	if (c == '.')
		return (1);
	return (0);
}

int			len_modifiers_detect(char c)
{
	if (c == 'l' || c == 'h' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

int			conversion_flags_detect(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
			|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x'
			|| c == 'X' || c == 'c' || c == 'C' || c == '%')
		return (1);
	return (0);
}

int			validity_check(char c)
{
	if (initial_flags_detect(c) || ft_isdigit(c) || precision_detect(c) ||
			len_modifiers_detect(c) || conversion_flags_detect(c))
		return (0);
	return (ERROR);
}
