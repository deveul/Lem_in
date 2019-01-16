/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:14:04 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/04/13 14:25:18 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (i < n && str1[i] != str2[i])
		return (str1[i] - str2[i]);
	while (i < n && str1[i] == str2[i])
	{
		i++;
		if (i < n && str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (0);
}
