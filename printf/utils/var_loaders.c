/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_loaders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 09:40:45 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/08 15:54:51 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		load_i(va_list *args)
{
	int			res;

	res = va_arg(*args, int);
	return ((intmax_t)res);
}

intmax_t		load_l(va_list *args)
{
	long		res;

	res = va_arg(*args, long);
	return ((intmax_t)res);
}

intmax_t		load_ll(va_list *args)
{
	long long	res;

	res = va_arg(*args, long long);
	return ((intmax_t)res);
}
