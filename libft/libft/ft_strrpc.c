/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 10:40:59 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/06/28 13:02:51 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrpc(const char *s, int c, int d)
{
	char	b;
	char	new;
	int		i;
	char	*ret;

	ret = (char *)s;
	b = (char)c;
	new = (char)d;
	i = 0;
	while (ret[i])
	{
		if (ret[i] == b)
		{
			ret[i] = new;
			return (&ret[i]);
		}
		i++;
	}
	if (ret[i] == '\0' && c == '\0')
		return (&ret[i]);
	return (NULL);
}
