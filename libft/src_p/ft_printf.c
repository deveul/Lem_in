/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:45:26 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 13:42:16 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	int	case_1(t_format *arg, t_control *ctr,
					const char *format, va_list av)
{
	if ((arg->type = check_conv(format, ctr->i)) == '0')
	{
		ctr->i += len_x(format, ctr->i, '\0');
		return (0);
	}
	ctr->len = len_x(format, ctr->i, arg->type);
	arg->str = ft_strsub(format, ctr->i + 1, ctr->len);
	ft_analyse(arg);
	ft_conversion(arg, av);
	if (arg->check == -1)
	{
		free_arg(arg);
		write(1, ctr->result, arg->save);
		ft_strdel(&ctr->result);
		free(arg);
		free(ctr);
		return (-1);
	}
	ctr->result = ft_memjoin(ctr->result, arg->res, ctr->ret, arg->count);
	ctr->ret += arg->count;
	arg->save = ctr->ret;
	ctr->i += (ft_strlen(arg->str) + 1);
	free_arg(arg);
	return (0);
}

static void	case_2(t_control *ctr, const char *format)
{
	char *tmp;

	tmp = NULL;
	ctr->len = len_x(format, ctr->i, '%');
	tmp = ft_strsub(format, ctr->i, ctr->len);
	ctr->result = ft_memjoin(ctr->result, tmp, ctr->ret, ctr->len);
	ctr->ret += ctr->len;
	ctr->i += ctr->len;
	ft_strdel(&tmp);
}

static	int	final(t_format *arg, t_control *ctr, va_list av)
{
	int ret;

	ret = ctr->ret;
	write(1, ctr->result, ctr->ret);
	ft_strdel(&ctr->result);
	free(ctr);
	free(arg);
	va_end(av);
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list		av;
	t_format	*arg;
	t_control	*ctr;

	if (format == NULL)
		return (-1);
	if (!(arg = ft_memalloc(sizeof(t_format))))
		exit(-1);
	if (!(ctr = ft_memalloc(sizeof(t_control))))
		exit(-1);
	init_struc(arg, ctr);
	va_start(av, format);
	while (format[ctr->i])
	{
		if (format[ctr->i] == '%')
		{
			if (case_1(arg, ctr, format, av) == -1)
				return (-1);
		}
		else
			case_2(ctr, format);
	}
	return (final(arg, ctr, av));
}
