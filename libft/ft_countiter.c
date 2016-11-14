/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:20:08 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/11/07 14:02:13 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_countiter(char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] == c)
				++count;
			++i;
		}
	}
	return (count);
}