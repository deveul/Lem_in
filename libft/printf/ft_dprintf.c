/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:40:28 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/02 16:02:20 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dprintf3(t_prf *prf, t_fmt arg)
{
	if (arg.conv != 'c' && arg.conv != 'C'
			&& arg.conv != 'S' && arg.conv != 's')
		prf->cpt[1] = ft_strlen(prf->tmp);
	ft_strdel(&prf->tmp2);
	if (!(prf->tmp2 = ft_memdup(prf->top, prf->cpt[2])))
		return (-1);
	ft_strdel(&prf->top);
	if (!(prf->top = ft_memjoin(prf->tmp2, prf->tmp, prf->cpt[2], prf->cpt[1])))
		return (-1);
	ft_del_prf(prf, &arg);
	prf->cpt[0] += arg.len;
	prf->cpt[2] += prf->cpt[1];
	return (1);
}

static int	ft_dprintf2(int fd, va_list ap, t_prf *prf, const char *format)
{
	t_fmt	arg;

	if (prf->cpt[3] == 0)
		prf->cpt[3] = prf->cpt[1];
	prf->cpt[1] = 0;
	arg = ft_analyze_arg(&format[++prf->cpt[0]]);
	if ((prf->tmp = ft_get_conv(ap, &arg, &prf->cpt[1])) == 0)
	{
		if (prf->tmp2)
			write(fd, prf->tmp2, prf->cpt[3]);
		else
			write(fd, prf->top, prf->cpt[3]);
		ft_del_prf2(prf, &arg);
		return (-1);
	}
	return (ft_dprintf3(prf, arg));
}

static int	ft_dprintf4(t_prf *prf, const char *format)
{
	if (!(prf->tmp2 = ft_memdup(prf->top, prf->cpt[2])))
		return (-1);
	prf->cpt[3] = prf->cpt[2];
	ft_strdel(&prf->top);
	if (!(prf->top = ft_memjoin(prf->tmp2, &format[prf->cpt[0]], prf->cpt[2],
			ft_strlenuntilc(&format[prf->cpt[0]], '%'))))
		return (-1);
	while (format[prf->cpt[0]] && format[prf->cpt[0]] != '%')
	{
		prf->cpt[0]++;
		prf->cpt[2]++;
	}
	return (0);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	t_prf	prf;

	if (!format)
		return (-1);
	ft_init_prf(&prf);
	if ((prf.cpt[0] = ft_get_arg_nb(format)) == 0)
		return (ft_only_fmt(fd, format));
	prf.cpt[0] = 0;
	va_start(ap, format);
	while (format[prf.cpt[0]])
	{
		if (format[prf.cpt[0]] == '%')
		{
			if ((ft_dprintf2(fd, ap, &prf, format)) == -1)
				return (-1);
		}
		else if ((ft_dprintf4(&prf, format)) == -1)
			return (-1);
	}
	va_end(ap);
	write(fd, prf.top, prf.cpt[2]);
	ft_strdel(&prf.tmp2);
	ft_del_prfo(&prf);
	return (prf.cpt[2]);
}
