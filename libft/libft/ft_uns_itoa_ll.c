/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_itoa_ll.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:25:14 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/09/07 16:16:42 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_put_in_str(int cpt, unsigned long long n, unsigned long long s)
{
	char				*snb;
	int					i;
	unsigned long long	save;

	save = n;
	i = 0;
	if ((snb = malloc(sizeof(char) * (cpt + 1))) == 0)
		return (NULL);
	while (i < cpt)
	{
		n = n / s;
		snb[i] = (n % 10) + 48;
		n = save;
		s = s / 10;
		i++;
	}
	snb[i] = '\0';
	return (snb);
}

char		*ft_uns_itoa_ll(unsigned long long n)
{
	unsigned long long	size;
	unsigned long long	save;
	unsigned long long	save2;
	int					cpt;

	cpt = 1;
	size = 1;
	save = n;
	save2 = save;
	while (save >= 10)
	{
		save = save / 10;
		size = size * 10;
		cpt++;
	}
	return (ft_put_in_str(cpt, save2, size));
}
