/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 08:43:12 by hmenzagh          #+#    #+#             */
/*   Updated: 2017/04/05 11:38:11 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_error(char *error_message, int error_code)
{
	ft_putstr(error_message);
	ft_putchar('\n');
	exit(error_code);
}
