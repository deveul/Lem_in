/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 16:23:51 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/04 16:06:14 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			ft_get_stype(va_list ap, t_fmt *para)
{
	long long	arg;

	arg = 0;
	if (para->size)
	{
		if (ft_strstr(para->size, "ll"))
			arg = va_arg(ap, long long);
		else if (ft_strchr(para->size, 'l'))
			arg = (long long)va_arg(ap, long);
		else if (ft_strchr(para->size, 'j'))
			arg = (long long)va_arg(ap, intmax_t);
		else if (ft_strchr(para->size, 'z'))
			arg = (long long)va_arg(ap, size_t);
		else if (ft_strstr(para->size, "hh"))
			arg = (char)(long long)va_arg(ap, int);
		else if (ft_strchr(para->size, 'h'))
			arg = (short)(long long)va_arg(ap, int);
	}
	else
		arg = (long long)va_arg(ap, int);
	return (arg);
}

unsigned long long	ft_get_unstype(va_list ap, t_fmt *para)
{
	unsigned long long	arg;

	arg = 0;
	if (para->size)
	{
		if (ft_strstr(para->size, "ll"))
			arg = va_arg(ap, unsigned long long);
		else if (ft_strchr(para->size, 'l'))
			arg = (unsigned long long)va_arg(ap, unsigned long);
		else if (ft_strchr(para->size, 'j'))
			arg = (unsigned long long)va_arg(ap, uintmax_t);
		else if (ft_strchr(para->size, 'z'))
			arg = (unsigned long long)va_arg(ap, size_t);
		else if (ft_strstr(para->size, "hh"))
			arg = (unsigned char)(unsigned long long)va_arg(ap, unsigned int);
		else if (ft_strchr(para->size, 'h'))
			arg = (unsigned short)(unsigned long long)va_arg(ap, unsigned int);
	}
	else
		arg = (unsigned long long)va_arg(ap, unsigned int);
	return (arg);
}
