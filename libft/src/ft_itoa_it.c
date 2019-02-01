/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:03:20 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:55:26 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t		ft_size(size_t n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char				*ft_itoa_it(size_t n)
{
	char	*str;
	size_t	size;

	size = ft_size(n);
	if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
		return (0);
	str[size] = '\0';
	size--;
	while (size + 1 > 0)
	{
		str[size] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	return (str);
}
