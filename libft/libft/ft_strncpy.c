/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:58:39 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/04/13 19:08:16 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int		i;
	size_t	c;

	i = 0;
	c = 0;
	while (src[i] && c < len)
	{
		dst[i] = src[i];
		i++;
		c++;
	}
	while (c < len)
	{
		dst[i] = '\0';
		i++;
		c++;
	}
	return (dst);
}
