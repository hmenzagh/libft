/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_magic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 08:45:37 by hmenzagh          #+#    #+#             */
/*   Updated: 2017/04/05 12:29:33 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		mv_all_right(char *s)
{
	int i;

	i = 0;
	while (s[i])
		++i;
	while (i > 0)
	{
		s[i] = s[i - 1];
		--i;
	}
	s[i] = '\0';
}

int				string_magic(char c, char **s, int start)
{
	int			i;

	if (*s == NULL)
	{
		if (!(*s = ft_memalloc(sizeof(char) * 2)))
			return (ERROR);
		(*s)[0] = c;
	}
	else
	{
		i = ft_strlen(*s);
		if (start == REPLACE)
			ft_realloc((void**)s, i, i + 2);
		if (start == START)
		{
			mv_all_right(*s);
			(*s)[0] = c;
		}
		else if (start == END)
			(*s)[i] = c;
		else if (start <= REPLACE)
			(*s)[start] = c;
	}
	return (0);
}
