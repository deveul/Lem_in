/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:08:06 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/02 17:36:41 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinone(char *s1, char c)
{
	char		*new;
	size_t		i;

	i = 0;
	if (!s1)
	{
		if (!(new = ft_memalloc(2)))
			return (NULL);
		new[0] = 'c';
		return (ft_strdup(&c));
	}
	if (!(new = ft_memalloc(ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = c;
	ft_strdel(&s1);
	return (new);
}
