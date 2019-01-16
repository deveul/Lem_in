/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:50:22 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/04/16 17:08:50 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	a;
	size_t			i;

	i = 0;
	a = (unsigned char)c;
	while (i < n)
	{
		if (((unsigned char*)s)[i] == a)
			return (char*)(&s[i]);
		i++;
	}
	return (NULL);
}
