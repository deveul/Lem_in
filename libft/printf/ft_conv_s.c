/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 19:55:42 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/04 15:59:58 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_arg(char *arg, t_fmt para)
{
	char	*str;
	int		len;

	len = ft_strlen(arg);
	if (para.acy == -1 || para.acy >= len)
		return (ft_strdup(arg));
	else
		return (ft_strndup(arg, para.acy));
	return (str);
}

static char	*ft_fill_str(char *str, t_fmt *para, int len)
{
	char	*tmp;

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

char		*ft_conv_str(va_list ap, t_fmt para, int *cpt)
{
	char	*arg;
	char	*str;
	int		len;

	arg = va_arg(ap, char*);
	if (!arg)
		arg = "(null)";
	if (!(str = ft_get_arg(arg, para)))
		return (NULL);
	len = ft_strlen(str);
	(*cpt) = len;
	if (para.width > len)
	{
		(*cpt) = para.width;
		return (ft_fill_str(str, &para, len));
	}
	return (str);
}
