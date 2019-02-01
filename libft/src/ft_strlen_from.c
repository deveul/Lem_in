/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_from.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 23:47:43 by sabri             #+#    #+#             */
/*   Updated: 2018/12/05 09:55:26 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strlen_from(char *str, char start, char end)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] && str[i] != start)
		i++;
	while (str[i + count] && str[i + count] != end)
		count++;
	return (count);
}
