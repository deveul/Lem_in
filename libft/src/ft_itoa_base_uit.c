/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:03:20 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:55:26 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_size(uintmax_t n, int base)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / base;
		size++;
	}
	return (size);
}

char			*ft_itoa_base_uit(uintmax_t n, int len, int flag)
{
	char	*str;
	int		size;
	char	*base;

	if (flag == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (len > 9)
		base = ft_strsub(base, 0, len);
	size = ft_size(n, len);
	if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
		return (0);
	str[size] = '\0';
	size--;
	while (size >= 0)
	{
		str[size] = base[n % len];
		n /= len;
		size--;
	}
	return (str);
}
