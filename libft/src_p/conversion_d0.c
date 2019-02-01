/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_d0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 12:33:02 by sabri             #+#    #+#             */
/*   Updated: 2018/12/05 09:57:38 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*conversion_d0(t_format *arg, char *nb, va_list av)
{
	if (arg->type == 'd' || arg->type == 'D' || arg->type == 'i')
		nb = conversion_d0_d(arg, nb, av);
	else if (arg->type == 'u' || arg->type == 'U')
		nb = conversion_d0_u(arg, nb, av);
	else if (arg->type == 'o' || arg->type == 'O')
		nb = conversion_d0_o(arg, nb, av);
	else if (arg->type == 'x' || arg->type == 'X')
		nb = conversion_d0_x(arg, nb, av);
	else if (arg->type == 'f' || arg->type == 'F')
		nb = conversion_f(arg, nb, av);
	return (nb);
}

char	*conversion_d0_d(t_format *arg, char *nb, va_list av)
{
	long x;

	x = va_arg(av, long);
	if (arg->size[0] == '\0' && arg->type != 'D')
		nb = ft_itoa((int)x);
	if (ft_strcmp(arg->size, "h") == 0 && arg->type != 'D')
		nb = ft_itoa((short)x);
	else if (ft_strcmp(arg->size, "hh") == 0 && arg->type != 'D')
		nb = ft_itoa((char)x);
	else if (arg->type == 'D' || (ft_strcmp(arg->size, "l") == 0))
		nb = ft_itoa_lli(x);
	return (nb);
}

char	*conversion_d0_u(t_format *arg, char *nb, va_list av)
{
	long x;

	x = va_arg(av, unsigned long);
	if (arg->size[0] == '\0' && arg->type == 'u')
		nb = ft_itoa_ui((unsigned int)x);
	if (ft_strcmp(arg->size, "h") == 0 && arg->type == 'u')
		nb = ft_itoa_ui((unsigned short)x);
	else if (ft_strcmp(arg->size, "hh") == 0 && arg->type == 'u')
		nb = ft_itoa_ui((unsigned char)x);
	else if (arg->type == 'U' || (ft_strcmp(arg->size, "l") == 0))
		nb = ft_itoa_lui(x);
	return (nb);
}

char	*conversion_d0_o(t_format *arg, char *nb, va_list av)
{
	long x;

	x = va_arg(av, unsigned long);
	if (arg->size[0] == '\0' && arg->type == 'o')
		nb = ft_itoa_base_ui((unsigned int)x, 8, 0);
	else if (ft_strcmp(arg->size, "h") == 0 && arg->type == 'o')
		nb = ft_itoa_base_ui((unsigned short)x, 8, 0);
	else if (ft_strcmp(arg->size, "hh") == 0 && arg->type == 'o')
		nb = ft_itoa_base_ui((unsigned char)x, 8, 0);
	else if (arg->type == 'O' || ft_strcmp(arg->size, "l") == 0)
		nb = ft_itoa_base_lui(x, 8, 0);
	return (nb);
}

char	*conversion_d0_x(t_format *arg, char *nb, va_list av)
{
	long	x;
	int		f;

	x = va_arg(av, unsigned long);
	if (arg->type == 'x')
		f = 0;
	else
		f = 1;
	if (arg->size[0] == '\0')
		nb = ft_itoa_base_ui((unsigned int)x, 16, f);
	else if (ft_strcmp(arg->size, "h") == 0)
		nb = ft_itoa_base_ui((unsigned short)x, 16, f);
	else if (ft_strcmp(arg->size, "hh") == 0)
		nb = ft_itoa_base_ui((unsigned char)x, 16, f);
	else if ((ft_strcmp(arg->size, "l") == 0))
		nb = ft_itoa_base_lui(x, 16, f);
	return (nb);
}
