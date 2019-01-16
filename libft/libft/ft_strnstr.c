/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:57:28 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/04/19 16:42:20 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *needle, size_t len)
{
	int		i[2];
	int		start;
	size_t	save;

	ft_memset(i, 0, 8);
	if (*needle == '\0')
		return (char *)(src);
	while (src[i[0]] && len > 0)
	{
		i[1] = 0;
		if (src[i[0]] == needle[i[1]])
		{
			start = i[0];
			save = len;
			while (src[i[0]++] == needle[i[1]++] && save-- > 0)
			{
				if (needle[i[1]] == '\0')
					return (char*)(src + start);
			}
			i[0] = start;
		}
		i[0]++;
		len--;
	}
	return (NULL);
}
