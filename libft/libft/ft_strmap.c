/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:11:23 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/04/19 15:18:48 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	size_t	size;
	char	*fresh;

	i = 0;
	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	if ((fresh = (char *)malloc(sizeof(char) * (size + 1))) == 0)
		return (NULL);
	while (s[i])
	{
		fresh[i] = f(s[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
