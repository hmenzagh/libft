/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_loaders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 09:40:45 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/08 15:54:24 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		load_short(va_list *args)
{
	short		res;

	res = (short)va_arg(*args, int);
	return ((intmax_t)res);
}

intmax_t		load_s_char(va_list *args)
{
	signed char	res;

	res = (signed char)va_arg(*args, int);
	return ((intmax_t)res);
}

intmax_t		load_imax(va_list *args)
{
	intmax_t	res;

	res = va_arg(*args, intmax_t);
	return ((intmax_t)res);
}

intmax_t		load_sst(va_list *args)
{
	ssize_t		res;

	res = va_arg(*args, ssize_t);
	return ((intmax_t)res);
}
