/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:25:14 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/04/19 14:36:25 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_put_in_str(int sign, int cpt, unsigned int n, int size)
{
	char			*snb;
	int				i;
	unsigned int	save;

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

char		*ft_itoa(int n)
{
	int				size;
	unsigned int	save;
	unsigned int	save2;
	int				cpt;
	int				sign;

	cpt = 1;
	size = 1;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		save = (unsigned int)-n;
		cpt++;
	}
	else
		save = (unsigned int)n;
	save2 = save;
	while (save >= 10)
	{
		save = save / 10;
		size = size * 10;
		cpt++;
	}
	return (ft_put_in_str(sign, cpt, save2, size));
}
