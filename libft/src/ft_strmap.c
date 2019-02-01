/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:01:40 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:55:26 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str_new;

	if (!s)
		return (NULL);
	i = 0;
	if ((str_new = malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (0);
	while (s[i])
	{
		str_new[i] = f(s[i]);
		i++;
	}
	str_new[i] = '\0';
	return (str_new);
}
