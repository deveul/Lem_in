/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:46:20 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/04/16 16:22:09 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*dst;
	size_t	src_len;
	size_t	dst_len;
	size_t	c_copied;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dest);
	c_copied = 0;
	if (dst_len >= size)
		return (src_len + size);
	dst = dest + dst_len;
	while (*src != '\0' && (c_copied < (size - dst_len - 1)))
	{
		*dst++ = *src++;
		c_copied++;
	}
	*dst = '\0';
	return (src_len + dst_len);
}
