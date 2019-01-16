/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 11:00:24 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/05 10:40:46 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char					*ft_width_is_bigger(char *str, t_fmt *para, int len)
{
	char			*tmp;

	if ((tmp = ft_memalloc(para->width - len + 1)) == 0)
		return (NULL);
	ft_memset(tmp, ' ', para->width - len);
	if (para->minus == 0 && para->zero == 0)
		return (str = ft_strjoinfreeall(tmp, str));
	if (para->minus == 1)
		return (str = ft_strjoinfreeall(str, tmp));
	if (para->zero == 1)
	{
		ft_strdel(&tmp);
		if ((tmp = ft_memalloc(para->width + 1)) == 0)
			return (NULL);
		tmp = ft_memset(tmp, '0', para->width);
		len--;
		para->width--;
		while (len >= 0)
			tmp[para->width--] = str[len--];
	}
	ft_strdel(&str);
	return (tmp);
}

char						*ft_conv_b(va_list ap, t_fmt para)
{
	char				*str;
	unsigned long long	arg;
	int					len;

	arg = ft_get_unstype(ap, &para);
	if (!(str = ft_dectobi_ll(arg)))
		return (NULL);
	len = ft_strlen(str);
	if (len < para.width)
		return (ft_width_is_bigger(str, &para, len));
	return (str);
}
