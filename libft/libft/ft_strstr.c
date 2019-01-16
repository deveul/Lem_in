/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:57:28 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/04/19 16:30:57 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *needle)
{
	int		i;
	int		c;
	int		start;
	int		save;

	i = 0;
	if (*needle == '\0')
		return (char*)(src);
	while (src[i])
	{
		c = 0;
		if (src[i] == needle[c])
		{
			start = i;
			save = i;
			while (src[save++] == needle[c++])
			{
				if (needle[c] == '\0')
					return (char*)(src + start);
			}
		}
		i++;
	}
	return (NULL);
}
