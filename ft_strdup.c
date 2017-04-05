/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:29:11 by hmenzagh          #+#    #+#             */
/*   Updated: 2017/04/05 12:18:15 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int		c;
	char	*cp;

	c = 0;
	while (s1[c])
		c++;
	c++;
	cp = ft_memalloc(c * sizeof(char));
	c = 0;
	while (s1[c])
	{
		cp[c] = s1[c];
		c++;
	}
	cp[c] = '\0';
	return (cp);
}
