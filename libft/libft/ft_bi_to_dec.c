/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bi_to_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:47:15 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/09/20 17:22:19 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_bi_to_dec(char *bi)
{
	int		len;
	int		i;
	int		nb;

	len = ft_strlen(bi);
	len--;
	nb = 0;
	i = 0;
	while (len >= 0)
	{
		nb = nb + (bi[len] - 48) * ft_power(2, i);
		len--;
		i++;
	}
	return (nb);
}
