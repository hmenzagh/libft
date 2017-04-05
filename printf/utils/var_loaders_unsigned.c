/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_loaders_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 09:56:33 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/08 15:55:04 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t				load_ui(va_list *args)
{
	unsigned int		res;

	res = va_arg(*args, unsigned int);
	return ((uintmax_t)res);
}

uintmax_t				load_ul(va_list *args)
{
	unsigned long		res;

	res = va_arg(*args, unsigned long);
	return ((uintmax_t)res);
}

uintmax_t				load_ull(va_list *args)
{
	unsigned long long	res;

	res = va_arg(*args, unsigned long long);
	return ((uintmax_t)res);
}
