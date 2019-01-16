/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_h.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 11:00:24 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/04 15:53:46 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char					*ft_get_arg(unsigned long long arg, t_fmt para)
{
	t_prf				prf;

	ft_init_prf(&prf);
	if ((prf.top = ft_dec_to_hex(arg, para.conv)) == 0)
		return (NULL);
	prf.cpt[1] = ft_strlen(prf.top);
	if (para.acy > (prf.cpt[0] = prf.cpt[1]))
		prf.cpt[0] = para.acy;
	if (para.acy != -1)
	{
		if ((prf.tmp = ft_memalloc(prf.cpt[0] - prf.cpt[1] + 1)) == 0)
			return (NULL);
		ft_memset(prf.tmp, '0', (prf.cpt[0] - prf.cpt[1]));
		if (!(prf.top = ft_strjoinfreeall(prf.tmp, prf.top)))
			return (NULL);
	}
	if (para.hash == 1 && arg != 0)
	{
		prf.cpt[0] += 2;
		if ((prf.top = ft_strjoinfreesec("0x", prf.top)) == 0)
			return (NULL);
	}
	if (para.hash == 1 && arg != 0)
		prf.top[1] = para.conv;
	return (prf.top);
}

static char					*ft_width_is_biggr(char *str, t_fmt *para, int len)
{
	char				*tmp;

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
		free(tmp);
		if ((tmp = ft_memalloc(para->width + 1)) == 0)
			return (NULL);
		tmp = ft_memset(tmp, '0', para->width);
		len--;
		para->width--;
		while (len >= 0)
			tmp[para->width--] = str[len--];
		if ((ft_strrpc(tmp, para->conv, '0')))
			tmp[1] = para->conv;
	}
	ft_strdel(&str);
	return (tmp);
}

char						*ft_conv_h(va_list ap, t_fmt para)
{
	char				*str;
	unsigned long long	arg;
	int					len;

	arg = ft_get_unstype(ap, &para);
	if (arg == 0 && para.acy == 0)
	{
		len = para.width;
		if ((str = ft_memalloc(len + 1)) == 0)
			return (NULL);
		ft_memset(str, ' ', len);
		return (str);
	}
	if (!(str = ft_get_arg(arg, para)))
		return (NULL);
	len = ft_strlen(str);
	if (len < para.width)
		return (ft_width_is_biggr(str, &para, len));
	return (str);
}
