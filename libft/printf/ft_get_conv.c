/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 16:29:41 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/04 16:32:39 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_conv2(va_list ap, t_fmt *arg, int *cpt)
{
	char	*str;

	str = NULL;
	if (arg->conv == 's' && ((!arg->size)
			|| (arg->size && !ft_strchr(arg->size, 'l'))))
		str = ft_conv_str(ap, *arg, cpt);
	if (arg->conv == 'S')
		str = ft_conv_ws(ap, *arg, cpt);
	if (arg->conv == 's' && arg->size && ft_strchr(arg->size, 'l'))
		str = ft_conv_ws(ap, *arg, cpt);
	if (arg->conv == 'c' && ((!arg->size)
			|| (arg->size && !ft_strchr(arg->size, 'l'))))
		str = ft_conv_c(ap, *arg, cpt);
	if (arg->conv == 'C')
		str = ft_conv_wc(ap, *arg, cpt);
	if (arg->conv == 'c' && arg->size && ft_strchr(arg->size, 'l'))
		str = ft_conv_wc(ap, *arg, cpt);
	if (arg->conv == 'b')
		str = ft_conv_b(ap, *arg);
	if (!ft_strchr("bsSpdDioOuUxXcC", arg->conv))
		str = ft_conv_error(*arg);
	return (str);
}

char		*ft_get_conv(va_list ap, t_fmt *arg, int *cpt)
{
	char	*str;

	str = NULL;
	if (arg->conv == 'D' || arg->conv == 'O' || arg->conv == 'U')
	{
		arg->conv = arg->conv + 32;
		if ((arg->size = ft_memalloc(2)) == 0)
			return (NULL);
		arg->size[0] = 'l';
	}
	if (arg->conv == 'd' || arg->conv == 'i')
		str = ft_conv_int(ap, *arg);
	if (arg->conv == 'u')
		str = ft_conv_u(ap, *arg);
	if (arg->conv == 'o')
		str = ft_conv_o(ap, *arg);
	if (arg->conv == 'x' || arg->conv == 'X')
		str = ft_conv_h(ap, *arg);
	if (arg->conv == 'p')
		str = ft_conv_p(ap, *arg);
	if (arg->conv == '%')
		str = ft_conv_per(*arg);
	if (!str)
		return (ft_get_conv2(ap, arg, cpt));
	return (str);
}
