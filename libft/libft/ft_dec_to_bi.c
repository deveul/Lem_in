/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_bi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:47:15 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/03 15:12:59 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dec_to_bi(unsigned int nb)
{
	char			*res;
	unsigned int	save;
	unsigned int	size;
	int				cpt;
	int				i;

	cpt = 1;
	size = 1;
	i = 0;
	save = nb;
	while (nb >= 2)
	{
		nb = nb / 2;
		size = size * 2;
		cpt++;
	}
	if ((res = ft_memalloc((cpt + 1))) == 0)
		return (NULL);
	while (cpt > 0)
	{
		res[i++] = ((save / size) % 2) + 48;
		size = size / 2;
		cpt--;
	}
	return (res);
}
