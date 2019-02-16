/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:58:12 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 13:40:09 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		init_struc(t_format *arg, t_control *ctr)
{
	arg->str = NULL;
	arg->len = 0;
	arg->option = NULL;
	arg->width = 0;
	arg->precision = 0;
	arg->size = NULL;
	arg->type = 0;
	arg->res = NULL;
	arg->check = 0;
	arg->count = 0;
	ctr->i = 0;
	ctr->result = NULL;
	ctr->ret = 0;
	ctr->len = 0;
	ctr->fd = 0;
}

void		free_arg(t_format *arg)
{
	ft_strdel(&arg->str);
	arg->len = 0;
	ft_strdel(&arg->option);
	arg->width = 0;
	arg->precision = 0;
	arg->type = 0;
	ft_strdel(&arg->res);
	arg->check = 0;
}

int			len_x(const char *str, int x, char c)
{
	int count;

	count = 1;
	while (str[x + count] && str[x + count] != c)
		count++;
	return (count);
}
