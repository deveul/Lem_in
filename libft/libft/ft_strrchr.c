/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 10:40:59 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/04/16 17:46:13 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	b;
	int		i;
	int		start;

	b = (char)c;
	i = 0;
	start = -1;
	if (b == '\0')
	{
		while (s[i])
			i++;
		return (char*)(&s[i]);
	}
	while (s[i])
	{
		if (s[i] == b)
			start = i;
		i++;
	}
	if (start != -1)
		return (char*)(&s[start]);
	return (NULL);
}
