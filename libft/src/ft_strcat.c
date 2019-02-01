/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:17:53 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:55:26 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (s1[x])
		x++;
	while (s2[i])
	{
		s1[i + x] = s2[i];
		i++;
	}
	s1[i + x] = '\0';
	return (s1);
}
