/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 10:40:59 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/19 16:12:28 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	b;
	int		i;
	char	*ret;

	ret = (char *)s;
	b = (char)c;
	i = 0;
	while (ret[i])
	{
		if (ret[i] == b)
			return (&ret[i]);
		i++;
	}
	if (ret[i] == '\0' && c == '\0')
		return (&ret[i]);
	return (NULL);
}
