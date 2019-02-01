/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:03:20 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:55:26 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_size(int n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	size = ft_size(n);
	if ((str = ft_memalloc(size + 1)) == NULL)
		return (0);
	str[size] = '\0';
	size--;
	if (n < 0)
	{
		str[i] = '-';
		i++;
		n = -n;
	}
	while (size >= i)
	{
		str[size] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	return (str);
}
