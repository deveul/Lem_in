/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:39:30 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:57:38 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_analyse(t_format *arg)
{
	arg->len = ft_strlen(arg->str);
	arg->option = check_option(arg->str);
	arg->width = check_widht(arg->str);
	arg->precision = check_precision(arg->str);
	arg->size = check_size(arg->str);
}

void	ft_conversion(t_format *arg, va_list av)
{
	if (arg->type == 'd' || arg->type == 'D' || arg->type == 'i'
			|| arg->type == 'u' || arg->type == 'U'
			|| arg->type == 'o' || arg->type == 'O'
			|| arg->type == 'x' || arg->type == 'X'
			|| arg->type == 'f' || arg->type == 'F')
		conversion_d(arg, av);
	else if (arg->type == 'c' || arg->type == 'C')
		conversion_c(arg, av);
	else if (arg->type == 's' || arg->type == 'S')
		conversion_s(arg, av);
	else if (arg->type == 'p')
		conversion_p(arg, av);
	else if (arg->type == '%')
		conversion_0(arg);
	else if (ft_strchr(SIZE, arg->type) == 0 && arg->type != '0')
		conversion_none(arg);
	return ;
}
