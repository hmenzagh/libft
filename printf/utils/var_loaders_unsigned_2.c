/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_loaders_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 09:56:33 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/08 15:54:38 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t				load_ushort(va_list *args)
{
	unsigned short		res;

	res = (unsigned short)va_arg(*args, int);
	return ((uintmax_t)res);
}

uintmax_t				load_u_char(va_list *args)
{
	unsigned char		res;

	res = (unsigned char)va_arg(*args, int);
	return ((uintmax_t)res);
}

uintmax_t				load_uimax(va_list *args)
{
	uintmax_t			res;

	res = va_arg(*args, uintmax_t);
	return ((uintmax_t)res);
}

uintmax_t				load_st(va_list *args)
{
	size_t		res;

	res = va_arg(*args, size_t);
	return ((uintmax_t)res);
}
