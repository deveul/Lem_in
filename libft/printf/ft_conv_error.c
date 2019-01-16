/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 17:39:47 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/04 15:47:08 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_error(t_fmt para)
{
	int		len;
	int		save;
	char	*str;
	char	*tmp;

	len = 1;
	save = len;
	if (para.conv == -1)
		return (ft_strdup(""));
	if (len < para.width)
		len = para.width;
	if (!(str = ft_memalloc(2)))
		return (NULL);
	str[0] = para.conv;
	if (!(tmp = ft_memalloc(len)))
		return (NULL);
	ft_memset(tmp, ' ', (len - 1));
	if (para.minus == 1)
		return (ft_strjoinfreeall(str, tmp));
	if (para.zero == 1)
	{
		ft_memset(tmp, '0', (len - 1));
		return (ft_strjoinfreeall(tmp, str));
	}
	return (ft_strjoinfreeall(tmp, str));
}
