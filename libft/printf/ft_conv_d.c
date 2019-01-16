/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 11:00:24 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/04 16:25:35 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_get_arg(long long arg, t_fmt para)
{
	t_prf			prf;

	ft_init_prf(&prf);
	prf.cpt[1] = ft_lololen(arg);
	prf.cpt[0] = prf.cpt[1];
	if (para.acy > prf.cpt[0])
		prf.cpt[0] = para.acy;
	if (arg < 0 && para.acy >= prf.cpt[1])
		prf.cpt[0]++;
	if (para.acy == -1)
		return (ft_itoa_ll(arg));
	if ((prf.tmp = ft_memalloc(prf.cpt[0] - prf.cpt[1] + 1)) == 0)
		return (NULL);
	ft_memset(prf.tmp, '0', (prf.cpt[0] - prf.cpt[1]));
	if (!(prf.tmp2 = ft_itoa_ll(arg)))
		return (NULL);
	if ((prf.top = ft_strjoin(prf.tmp, prf.tmp2)) == NULL)
		return (NULL);
	ft_strdel(&prf.tmp);
	ft_strdel(&prf.tmp2);
	if (arg < 0)
		prf.top[0] = '-';
	if (arg < 0 && prf.cpt[0] != prf.cpt[1])
		prf.top[prf.cpt[0] - prf.cpt[1]] = '0';
	return (prf.top);
}

static char			*ft_width_is_bigger2(char *str, t_fmt *para, int len)
{
	char			*tmp;

	if ((tmp = ft_memalloc(para->width + 1)) == 0)
		return (NULL);
	tmp = ft_memset(tmp, '0', para->width);
	len--;
	para->width--;
	while (len >= 0)
	{
		if (str[len] == '+' || str[len] == ' ' || str[len] == '-')
		{
			tmp[0] = str[len];
			break ;
		}
		tmp[para->width--] = str[len--];
	}
	ft_strdel(&str);
	return (tmp);
}

static char			*ft_width_is_bigger(char *str, t_fmt *para, int len)
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
	ft_strdel(&tmp);
	return (ft_width_is_bigger2(str, para, len));
}

static char			*ft_len_is_bigger(char *str, t_fmt *para)
{
	char			*tmp;

	if (str[0] != '-' && (para->plus == 1 || para->space == 1))
	{
		if (para->plus == 1)
		{
			if (!(tmp = ft_strjoin("+", str)))
				return (NULL);
			ft_strdel(&str);
		}
		if (para->space == 1 && para->plus == 0)
		{
			if (!(tmp = ft_strjoin(" ", str)))
				return (NULL);
			ft_strdel(&str);
		}
		return (tmp);
	}
	return (str);
}

char				*ft_conv_int(va_list ap, t_fmt para)
{
	char			*str;
	long long		arg;
	int				len;

	arg = ft_get_stype(ap, &para);
	if (arg == 0 && para.acy == 0)
	{
		len = para.width;
		if ((para.plus == 1 && len == 0)
				|| (para.space == 1 && para.plus == 0 && len == 0))
			len++;
		if ((str = ft_memalloc(len + 1)) == 0)
			return (NULL);
		ft_memset(str, ' ', len);
		if (para.plus == 1)
			str[--len] = '+';
		return (str);
	}
	if (!(str = ft_get_arg(arg, para)))
		return (NULL);
	if (!(str = ft_len_is_bigger(str, &para)))
		return (NULL);
	if ((len = ft_strlen(str)) < para.width)
		return (ft_width_is_bigger(str, &para, len));
	return (str);
}
