/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:27:01 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/03 19:06:01 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wstrlen(const wchar_t *s)
{
	size_t		i;
	size_t		cpt;

	i = 0;
	cpt = 0;
	while (s[i])
	{
		cpt += ft_charlen(s[i]);
		i++;
	}
	return (cpt);
}
