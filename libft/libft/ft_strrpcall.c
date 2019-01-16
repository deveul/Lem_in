/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrpcall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 10:40:59 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/09/24 10:50:14 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrpcall(char *s, int c, int d)
{
	char	b;
	char	new;
	int		i;

	b = (char)c;
	new = (char)d;
	i = 0;
	while (s[i])
	{
		if (s[i] == b)
			s[i] = new;
		i++;
	}
	return (s);
}
