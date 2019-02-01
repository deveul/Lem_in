/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_f0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 13:37:20 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:57:38 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	char	*conversion_df(t_format *arg, char *nb, va_list av)
{
	double x;

	x = va_arg(av, double);
	nb = ft_itoa_f(arg, x);
	return (nb);
}

static	char	*conversion_ldf(t_format *arg, char *nb, va_list av)
{
	long double x;

	x = va_arg(av, long double);
	nb = ft_itoa_bf(arg, x);
	return (nb);
}

char			*f0(int precision)
{
	char *tmp;

	tmp = NULL;
	if (precision == 0)
		return (ft_strdup("0"));
	if (!(tmp = ft_memalloc(precision + 1)))
		exit(-1);
	ft_memset(tmp, '0', precision);
	tmp = ft_strjoin_free("0.", tmp);
	return (tmp);
}

char			*conversion_f(t_format *arg, char *nb, va_list av)
{
	if (ft_strchr(arg->str, 'L') != 0)
		nb = conversion_ldf(arg, nb, av);
	else
		nb = conversion_df(arg, nb, av);
	return (nb);
}
