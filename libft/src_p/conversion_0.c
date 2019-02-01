/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 01:10:30 by sabri             #+#    #+#             */
/*   Updated: 2018/12/05 09:57:38 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	void	case_1(t_format *arg)
{
	if (!(arg->res = ft_memalloc(arg->width + 1)))
		exit(-1);
	ft_memset(arg->res, ' ', arg->width);
	arg->res[0] = '%';
}

static	void	conversion_0_1(t_format *arg)
{
	if (!(arg->res = ft_memalloc(arg->width + 1)))
		exit(-1);
	ft_memset(arg->res, '0', arg->width);
	arg->res[arg->width - 1] = '%';
}

static	void	conversion_0_2(t_format *arg)
{
	if (!(arg->res = ft_memalloc(arg->width + 1)))
		exit(-1);
	ft_memset(arg->res, ' ', arg->width);
	arg->res[arg->width - 1] = '%';
}

void			conversion_0(t_format *arg)
{
	if (arg->width > 1)
	{
		if (ft_strchr(arg->option, '-') != 0)
			case_1(arg);
		else if (ft_strchr(arg->option, '0') != 0)
			conversion_0_1(arg);
		else
			conversion_0_2(arg);
	}
	else
	{
		if (!(arg->res = ft_memalloc(2)))
			exit(-1);
		arg->res[0] = '%';
	}
	arg->count = ft_strlen(arg->res);
}
