/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:03:20 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:55:26 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_size(int n, int base)
{
	int		size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n != 0)
	{
		n = n / base;
		size++;
	}
	return (size);
}

static	char	*check_base(int len, int flag)
{
	char	*base;

	if (flag == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (len > 9)
		base = ft_strsub(base, 0, len);
	return (base);
}

char			*ft_itoa_base(int n, int len, int flag)
{
	char	*str;
	int		i;
	int		size;
	char	*base;

	i = 0;
	base = check_base(len, flag);
	size = ft_size(n, len);
	if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
		return (0);
	str[size--] = '\0';
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	while (size >= i)
	{
		str[size--] = base[n % len];
		n /= len;
	}
	return (str);
}
