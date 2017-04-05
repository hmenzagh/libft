/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handelers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:54:20 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/11/29 11:04:01 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			initial_flags(char *format, int *pos, t_info *chunk)
{
	int		check;

	check = 1;
	if (initial_flags_detect(format[*pos]))
	{
		while (initial_flags_detect(format[*pos]))
		{
			if (format[*pos] == '0')
				chunk->zero_pad = 1;
			else if (format[*pos] == '#')
				chunk->hashtag = 1;
			else if (format[*pos] == '+')
				chunk->positive = 1;
			else if (format[*pos] == '-')
				chunk->negative = 1;
			else
				chunk->space = 1;
			++(*pos);
		}
		return (1);
	}
	return (validity_check(format[*pos]));
}

int			minimum_field(char *format, int *pos, t_info *chunk)
{
	int		o_pos;
	char	c_save;

	o_pos = *pos;
	while (ft_isdigit(format[*pos]))
		++(*pos);
	if (o_pos != *pos)
	{
		c_save = format[*pos];
		format[*pos] = '\0';
		chunk->minimum_field = ft_atoi(format + o_pos);
		format[*pos] = c_save;
		return (1);
	}
	return (validity_check(format[*pos]));
}

int			precision(char *format, int *pos, t_info *chunk)
{
	int		o_pos;
	char	c_save;
	int		p_value;

	if (precision_detect(format[*pos]) && ++(*pos))
	{
		o_pos = *pos;
		if (ft_isdigit(format[*pos]))
		{
			while (ft_isdigit(format[*pos]))
				++(*pos);
			c_save = format[*pos];
			format[*pos] = '\0';
			p_value = ft_atoi(format + o_pos);
			chunk->precision = (p_value) ? p_value : -1;
			format[*pos] = c_save;
		}
		else
			chunk->precision = -1;
		return (1);
	}
	return (validity_check(format[*pos]));
}

int			len_modifiers(char *format, int *pos, t_info *chunk)
{
	if (len_modifiers_detect(format[*pos]))
	{
		if (format[*pos] == 'h' || format[*pos] == 'l')
		{
			chunk->len_modifier = (format[*pos] == 'h') ? 2 : 4;
			if (format[*pos + 1] == format[*pos])
			{
				--(chunk->len_modifier);
				++(*pos);
			}
		}
		else
			chunk->len_modifier = (format[*pos] == 'j') ? 5 : 6;
		++(*pos);
		return (1);
	}
	chunk->len_modifier = 0;
	return (validity_check(format[*pos]));
}

int			conversion_flags(char *format, int *pos, t_info *chunk)
{
	if (conversion_flags_detect(format[*pos]))
	{
		chunk->conversion = format[*pos];
		++(*pos);
	}
	else
		return (ERROR);
	return (1);
}
