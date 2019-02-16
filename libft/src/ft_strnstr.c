/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:14:05 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:55:30 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (find[i] == '\0')
		return ((char *)str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == find[j] && (i + j) < len)
		{
			if (find[j + 1] == '\0')
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
