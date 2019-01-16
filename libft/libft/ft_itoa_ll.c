/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:25:14 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/09/07 16:20:03 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_put_in_str(int sign, int cpt,
		unsigned long long n, unsigned long long size)
{
	char				*snb;
	int					i;
	unsigned long long	save;

	save = n;
	i = 0;
	if ((snb = malloc(sizeof(char) * (cpt + 1))) == 0)
		return (NULL);
	if (sign == 1)
	{
		snb[i] = '-';
		i++;
	}
	while (i < cpt)
	{
		n = n / size;
		snb[i] = (n % 10) + 48;
		n = save;
		size = size / 10;
		i++;
	}
	snb[i] = '\0';
	return (snb);
}

char		*ft_itoa_ll(long long n)
{
	unsigned long long	size;
	unsigned long long	save;
	unsigned long long	save2;
	int					cpt;
	int					sign;

	cpt = 1;
	size = 1;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		save = (unsigned long long)-n;
		cpt++;
	}
	else
		save = (unsigned long long)n;
	save2 = save;
	while (save >= 10)
	{
		save = save / 10;
		size = size * 10;
		cpt++;
	}
	return (ft_put_in_str(sign, cpt, save2, size));
}
