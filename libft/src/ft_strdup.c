/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 12:31:19 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:55:26 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *src)
{
	size_t		i;
	size_t		x;
	char		*str;

	i = 0;
	x = ft_strlen(src);
	if ((str = malloc(sizeof(char) * x + 1)) == NULL)
		return (0);
	while (i < x)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
