/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:45:11 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/06/27 11:40:25 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uintmax_to_hex(uintmax_t nb, char c)
{
	char		*b;
	char		*res;
	uintmax_t	save;
	uintmax_t	size;
	int			cpt[2];

	cpt[0] = 0;
	cpt[1] = 1;
	size = 1;
	save = nb;
	b = "0123456789abcdef";
	if (c == 'X')
		b = "0123456789ABCDEF";
	while ((nb /= 16) > 0 && cpt[1]++)
		size = size * 16;
	if ((res = ft_memalloc((cpt[1] + 1))) == 0)
		return (NULL);
	while (cpt[1]-- > 0)
	{
		res[cpt[0]++] = b[((save / size) % 16)];
		size = size / 16;
	}
	return (res);
}
