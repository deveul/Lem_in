/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 19:22:09 by sabri             #+#    #+#             */
/*   Updated: 2018/12/05 09:57:38 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	char	*conversion_p1(t_format *arg, char *tmp, char *str_tmp)
{
	if (!(str_tmp = ft_memalloc(arg->precision - (int)ft_strlen(tmp) + 3)))
		exit(-1);
	ft_memset(str_tmp, '0', arg->precision - (int)ft_strlen(tmp) + 3);
	str_tmp[0] = '0';
	str_tmp[1] = 'x';
	str_tmp[arg->precision - (int)ft_strlen(tmp) + 2] = '\0';
	return (str_tmp);
}

static void		conversion_p2(t_format *arg, char *str_tmp)
{
	if (!(arg->res = ft_memalloc(arg->width - (int)ft_strlen(str_tmp) + 1)))
		exit(-1);
	if (ft_strchr(arg->option, '0') != 0 && ft_strchr(arg->option, '-') == 0)
		ft_memset(arg->res, '0', arg->width - (int)ft_strlen(str_tmp));
	else
		ft_memset(arg->res, ' ', arg->width - (int)ft_strlen(str_tmp));
	if (ft_strchr(arg->option, '0') != 0 || ft_strchr(arg->option, '-') != 0)
		arg->res = ft_strjoin(str_tmp, arg->res);
	else
		arg->res = ft_strjoin(arg->res, str_tmp);
}

static void		conversion_p3(t_format *arg, char *str_tmp)
{
	if (arg->width > (int)ft_strlen(str_tmp))
		conversion_p2(arg, str_tmp);
	else
		arg->res = ft_strdup(str_tmp);
}

void			conversion_p(t_format *arg, va_list av)
{
	void				*adr;
	char				*tmp;
	char				*str_tmp;
	unsigned long		nb;

	str_tmp = NULL;
	tmp = NULL;
	adr = va_arg(av, void*);
	nb = (unsigned long)adr;
	tmp = ft_itoa_base_lui(nb, 16, 0);
	if ((int)ft_strlen(tmp) >= arg->precision)
		str_tmp = ft_strdup("0x");
	else
		str_tmp = conversion_p1(arg, tmp, str_tmp);
	if (ft_strcmp(tmp, "0") == 0 && arg->precision == 0
			&& ft_strchr(arg->str, '.') != 0)
		ft_strdel(&tmp);
	else
	{
		str_tmp = ft_memjoin(str_tmp, tmp, ft_strlen(str_tmp), ft_strlen(tmp));
		ft_strdel(&tmp);
	}
	conversion_p3(arg, str_tmp);
	ft_strdel(&str_tmp);
	arg->count = ft_strlen(arg->res);
}
