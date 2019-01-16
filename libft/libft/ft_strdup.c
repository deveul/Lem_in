/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:14:05 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/02 15:34:22 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		a;
	char	*dup;

	a = 0;
	if (!src)
		return (NULL);
	i = ft_strlen(src);
	if ((dup = ft_memalloc(i + 1)) == 0)
		return (NULL);
	while (a < i)
	{
		dup[a] = src[a];
		a++;
	}
	return (dup);
}
