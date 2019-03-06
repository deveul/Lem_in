/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:02:07 by smakni            #+#    #+#             */
/*   Updated: 2019/03/06 15:26:05 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		tmp[i] = 0;
		i++;
	}
	return (0);
}
