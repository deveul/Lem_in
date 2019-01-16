/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_wc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:58:16 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/04 15:56:24 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_conv_bzer(t_fmt para, int *cpt)
{
	int		len;
	int		i;
	char	*str;

	len = 1;
	i = 0;
	if (para.width > 1)
		len = para.width;
	(*cpt) = len;
	if ((str = ft_memalloc(len + 1)) == 0)
		return (NULL);
	if (para.minus == 1)
	{
		i++;
		while (1 < len--)
			str[i++] = ' ';
	}
	else
	{
		if (para.zero == 1)
			ft_memset(str, '0', (len - 1));
		else
			ft_memset(str, ' ', (len - 1));
	}
	return (str);
}

static int	ft_check_arg(int arg)
{
	if ((arg > 55295 && arg < 57344) || arg > 1114111)
		return (0);
	return (1);
}

static char	*ft_conv_char(t_fmt para, int *cpt, int argu)
{
	char	*arg;
	int		len;
	int		i;

	arg = NULL;
	len = 1;
	if (para.width > 0)
		len = para.width;
	if ((arg = ft_memalloc(len + 1)) == 0)
		return (NULL);
	i = 0;
	while (i < len)
		arg[i++] = ' ';
	if (para.minus == 1)
		arg[0] = argu;
	else
		arg[len - 1] = argu;
	(*cpt) = len;
	return (arg);
}

static char	*ft_width_is_bigger(char *arg, t_fmt para, int *cpt)
{
	int		len;
	char	*tmp;
	char	*tmp2;

	len = para.width;
	if (!(tmp = ft_strdup(arg)))
		return (NULL);
	ft_strdel(&arg);
	if ((tmp2 = ft_memalloc(len - (*cpt) + 1)) == 0)
		return (NULL);
	ft_memset(tmp2, ' ', (len - (*cpt)));
	if (para.minus == 1)
		arg = ft_strjoinfreeall(tmp, tmp2);
	else
		arg = ft_strjoinfreeall(tmp2, tmp);
	(*cpt) = len;
	return (arg);
}

char		*ft_conv_wc(va_list ap, t_fmt para, int *cpt)
{
	char	*arg;
	int		argu;

	argu = va_arg(ap, wchar_t);
	if (argu == 0)
		return (ft_conv_bzer(para, cpt));
	if (!ft_check_arg(argu))
		return (NULL);
	if (argu < 256 && MB_CUR_MAX == 1)
		return (ft_conv_char(para, cpt, argu));
	if ((arg = ft_putwcinstr(argu)) == 0)
		return (NULL);
	(*cpt) = ft_strlen(arg);
	if (para.width > (*cpt))
		return (ft_width_is_bigger(arg, para, cpt));
	return (arg);
}
