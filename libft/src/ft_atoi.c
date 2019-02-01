/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 12:40:46 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 10:03:49 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static long			ft_checkover(unsigned long x, int s)
{
	if (x > LONG_MAX && s == 1)
		return (-1);
	if (x > LONG_MAX && s == -1)
		return (0);
	return (x * s);
}

long				ft_atoi(const char *str)
{
	int		i;
	size_t	x;
	int		s;

	i = 0;
	x = 0;
	s = 1;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\t' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		x = (x * 10) + str[i] - '0';
		i++;
	}
	return (ft_checkover(x, s));
}
