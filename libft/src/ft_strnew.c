/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:15:59 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:55:30 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnew(size_t size)
{
	char	*str_new;
	size_t	i;

	i = 0;
	if ((str_new = malloc(sizeof(char) * (size + 1))) == NULL)
		return (0);
	while (i < size)
	{
		str_new[i] = '\0';
		i++;
	}
	str_new[i] = '\0';
	return (str_new);
}
