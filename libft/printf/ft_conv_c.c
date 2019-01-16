/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:58:16 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/04 11:02:09 by vrenaudi         ###   ########.fr       */
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

char		*ft_conv_c(va_list ap, t_fmt para, int *cpt)
{
	char	*arg;
	int		argu;
	int		len;

	argu = va_arg(ap, int);
	arg = NULL;
	if (argu == 0)
		return (ft_conv_bzer(para, cpt));
	len = 1;
	if (para.width > 0)
		len = para.width;
	if ((arg = ft_memalloc(len + 1)) == 0)
		return (NULL);
	if (para.zero == 1 && para.minus == 0)
		ft_memset(arg, '0', len);
	else
		ft_memset(arg, ' ', len);
	if (para.minus == 1)
		arg[0] = argu;
	else
		arg[len - 1] = argu;
	(*cpt) = len;
	return (arg);
}
