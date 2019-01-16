/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 17:43:22 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/04/18 16:31:30 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*fresh;

	if ((fresh = (char *)malloc(sizeof(char) * (size + 1))) == 0)
		return (NULL);
	ft_bzero(fresh, (size + 1));
	return (fresh);
}
