/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 10:24:38 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/04/18 15:53:20 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;
	unsigned char	a;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	a = (unsigned char)c;
	while (i < n)
	{
		d[i] = s[i];
		if (a == d[i])
		{
			i++;
			return (&(d[i]));
		}
		i++;
	}
	return (NULL);
}
