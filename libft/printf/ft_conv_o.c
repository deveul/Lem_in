/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 11:00:24 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/04 15:59:26 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char					*ft_get_arg(unsigned long long arg, t_fmt para)
{
	t_prf			prf;

	ft_init_prf(&prf);
	if ((prf.top = ft_dec_to_octa(arg)) == 0)
		return (NULL);
	prf.cpt[1] = ft_strlen(prf.top);
	prf.cpt[0] = prf.cpt[1];
	if (para.acy > prf.cpt[0])
		prf.cpt[0] = para.acy;
	if (para.hash == 1 && para.acy <= prf.cpt[1] && arg != 0)
		if ((prf.top = ft_strjoinfreesec("0", prf.top)) == 0)
			return (NULL);
	if (para.acy == -1)
		return (prf.top);
	if ((prf.tmp = ft_memalloc(prf.cpt[0] - prf.cpt[1] + 1)) == 0)
		return (NULL);
	ft_memset(prf.tmp, '0', (prf.cpt[0] - prf.cpt[1]));
	if ((prf.top = ft_strjoinfreeall(prf.tmp, prf.top)) == 0)
		return (NULL);
	return (prf.top);
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

static char					*ft_zero(t_fmt para)
{
	char				*str;
	int					len;

	len = para.width;
	if ((str = ft_memalloc(len + 1)) == 0)
		return (NULL);
	ft_memset(str, ' ', len);
	if (para.hash == 1)
	{
		if (len == 0)
		{
			ft_strdel(&str);
			if ((str = ft_memalloc(2)) == 0)
				return (NULL);
			str[0] = '0';
		}
		else
			str[--len] = '0';
	}
	return (str);
}

char						*ft_conv_o(va_list ap, t_fmt para)
{
	char				*str;
	unsigned long long	arg;
	int					len;

	arg = ft_get_unstype(ap, &para);
	if (arg == 0 && para.acy == 0)
		return (ft_zero(para));
	if (!(str = ft_get_arg(arg, para)))
		return (NULL);
	len = ft_strlen(str);
	if (len < para.width)
		return (ft_width_is_bigger(str, &para, len));
	return (str);
}
