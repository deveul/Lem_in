/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 10:19:01 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:55:26 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memjoin(void *s1, const void *s2, size_t n1, size_t n2)
{
	void	*res;

	res = NULL;
	if (!s1)
	{
		if (!(res = ft_memalloc(n2 + 1)))
			return (0);
		return (ft_memcpy(res, s2, n2));
	}
	if (s1 && s2)
	{
		if (!(res = ft_memalloc(n1 + n2 + 1)))
			return (0);
		res = ft_memcpy(res, s1, n1);
		res = ft_memcpy_from(res, s2, n1, n2);
		ft_memdel(&s1);
	}
	return (res);
}
