/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:08:06 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/04/19 15:56:26 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	int			size;
	char		*new;
	size_t		i;
	size_t		c;

	i = 0;
	c = 0;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + (n);
	if ((new = malloc(sizeof(char) * (size + 1))) == 0)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[c] && c < n)
	{
		new[i] = s2[c];
		i++;
		c++;
	}
	new[i] = '\0';
	return (new);
}
