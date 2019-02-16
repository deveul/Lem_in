/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:15:45 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:55:26 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_joined;
	int		len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((str_joined = malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	while (s1[i])
	{
		str_joined[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str_joined[i + j] = s2[j];
		j++;
	}
	str_joined[i + j] = '\0';
	return (str_joined);
}
