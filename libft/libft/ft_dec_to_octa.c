/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_octa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:47:15 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/09/07 14:12:40 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dec_to_octa(unsigned long long nb)
{
	char				*res;
	unsigned long long	save;
	unsigned long long	size;
	int					cpt;
	int					i;

	cpt = 1;
	size = 1;
	i = 0;
	save = nb;
	while (nb >= 8)
	{
		nb = nb / 8;
		size = size * 8;
		cpt++;
	}
	if ((res = ft_memalloc((cpt + 1))) == 0)
		return (NULL);
	while (cpt > 0)
	{
		res[i++] = ((save / size) % 8) + 48;
		size = size / 8;
		cpt--;
	}
	return (res);
}
