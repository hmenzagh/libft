/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:46:46 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/08 16:47:14 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					check_zero(const char *s)
{
	int				i;
	int				count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '0')
			++count;
		if (count > 1)
			return (0);
		if (s[i] != ' ' && s[i] != '0')
			return (0);
		++i;
	}
	return (1);
}
