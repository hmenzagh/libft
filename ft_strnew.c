/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:40:56 by hmenzagh          #+#    #+#             */
/*   Updated: 2017/04/05 12:18:23 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*chaine;
	int		s;

	s = ++size;
	chaine = ft_memalloc(s * sizeof(char));
	while (--s >= 0)
		chaine[s] = '\0';
	return (chaine);
}
