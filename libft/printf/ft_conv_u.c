/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 11:00:24 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/04 15:50:47 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char					*ft_get_arg(unsigned long long arg, t_fmt para)
{
	char			*str;
	char			*tmp;
	char			*tmp2;
	int				len;
	int				ulololen;

	ulololen = ft_unslololen(arg);
	len = ulololen;
	if (para.acy > len)
		len = para.acy;
	if (para.acy == -1)
	{
		str = ft_uns_itoa_ll(arg);
		return (str);
	}
	if ((tmp = ft_memalloc(len - ulololen + 1)) == 0)
		return (NULL);
	ft_memset(tmp, '0', (len - ulololen));
	if ((tmp2 = ft_uns_itoa_ll(arg)) == 0)
		return (NULL);
	if ((str = ft_strjoin(tmp, tmp2)) == 0)
		return (NULL);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	return (str);
}

static char					*ft_width_is_bigger(char *str, t_fmt *para, int len)
{
	char			*tmp;

	if ((tmp = ft_memalloc(para->width - len + 1)) == 0)
		return (NULL);
	ft_memset(tmp, ' ', para->width - len);
	if ((para->minus == 0 && para->acy != -1)
			|| (para->minus == 0 && para->zero == 0))
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

char						*ft_conv_u(va_list ap, t_fmt para)
{
	char				*str;
	unsigned long long	arg;
	int					len;

	arg = ft_get_unstype(ap, &para);
	if (arg == 0 && para.acy == 0)
	{
		if ((str = ft_memalloc(1)) == 0)
			return (NULL);
		return (str);
	}
	if (!(str = ft_get_arg(arg, para)))
		return (NULL);
	len = ft_strlen(str);
	if (len < para.width)
		return (ft_width_is_bigger(str, &para, len));
	return (str);
}
