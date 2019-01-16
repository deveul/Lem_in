/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ws.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 19:55:42 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/22 11:11:08 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_arg(wchar_t *arg, t_fmt para)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	str = NULL;
	if (para.acy == 0)
		return (ft_strdup(""));
	if (para.acy == -1)
	{
		while (arg[i])
			if (!(str = ft_strjoinfreeall(str, ft_putwcinstr(arg[i++]))))
				return (NULL);
	}
	else
		while ((para.acy -= ft_charlen(arg[i])) >= 0)
			if (!(str = ft_strjoinfreeall(str, ft_putwcinstr(arg[i++]))))
				return (NULL);
	if (!str)
		return (str = ft_strdup(""));
	return (str);
}

static char	*ft_fill_str(char *str, t_fmt *para, int len, int *cpt)
{
	char	*tmp;

	(*cpt) = para->width;
	if ((tmp = ft_memalloc(para->width - len + 1)) == 0)
		return (NULL);
	ft_memset(tmp, ' ', (para->width - len));
	if (para->minus == 0)
	{
		if (para->zero == 1)
			ft_memset(tmp, '0', (para->width - len));
		return (ft_strjoin(tmp, str));
	}
	return (ft_strjoin(str, tmp));
}

char		*ft_conv_ws(va_list ap, t_fmt para, int *cpt)
{
	wchar_t	*arg;
	char	*str;
	int		len;
	int		i;

	arg = va_arg(ap, wchar_t *);
	i = 0;
	len = 0;
	str = NULL;
	if (!arg)
	{
		(*cpt) = 6;
		return (ft_strdup("(null)"));
	}
	if (!(str = ft_get_arg(arg, para)))
		return (NULL);
	len = ft_strlen(str);
	(*cpt) = len;
	if (para.width > len)
		return (ft_fill_str(str, &para, len, cpt));
	return (str);
}
