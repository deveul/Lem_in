/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reversebits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:21:48 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/04/18 14:44:49 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_reversebits(unsigned char octet)
{
	unsigned char	reversed;
	int				i;

	i = 0;
	reversed = 0;
	while (i < 8)
	{
		reversed = reversed | ((1 & (octet >> i)) << (7 - i));
		i++;
	}
	return (reversed);
}
