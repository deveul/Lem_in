/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:40:29 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:55:26 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long i;
	unsigned long lendst;
	unsigned long j;

	i = 0;
	j = 0;
	if (ft_strlen((const char *)dst) >= size)
		return (ft_strlen(src) + size);
	while (dst[i] && i < size)
		i++;
	lendst = i;
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	if (lendst < size)
		dst[i] = '\0';
	return (lendst + ft_strlen(src));
}
