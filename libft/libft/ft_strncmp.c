/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 12:56:50 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/04/11 14:38:44 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (s1[i] != 0 && i < n && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	if (i < n && ((unsigned char)s1[i] != (unsigned char)s2[i]))
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
