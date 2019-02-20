/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_from.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:29:55 by smakni            #+#    #+#             */
/*   Updated: 2019/02/01 12:00:47 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcpy_from(char *dst, const char *src, int start)
{
	int i;

	i = 0;
	while (src[i + start])
	{
		dst[i] = src[i + start];
		i++;
	}
	dst[i + start] = '\0';
	return (dst);
}
