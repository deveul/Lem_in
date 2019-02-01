/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:02:21 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:55:26 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	if (src >= dst)
		return (ft_memcpy(dst, src, len));
	else
	{
		while (len--)
			dst_tmp[len] = src_tmp[len];
	}
	return (dst);
}
