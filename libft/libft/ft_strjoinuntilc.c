/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinuntilc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 10:52:16 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/09/26 17:16:51 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinuntilc(char *s1, const char *s2, char c)
{
	int		size;
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s2)
		return (NULL);
	if (!s1)
	{
		size = ft_strlenuntilc(s2, c);
		return (ft_strndup(s2, size));
	}
	size = ft_strlen(s1) + ft_strlenuntilc(s2, c);
	if ((new = malloc(sizeof(char) * (size + 1))) == 0)
		return (NULL);
	new[size] = '\0';
	while (s1[++i])
		new[i] = s1[i];
	while (s2[j] && s2[j] != c)
		new[i++] = s2[j++];
	ft_strdel(&s1);
	return (new);
}
