/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 18:32:05 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:55:30 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	while (s[i] != (char)c && i >= 0)
		i--;
	if (s[i] != (char)c)
		return (0);
	return ((char*)&s[i]);
}
