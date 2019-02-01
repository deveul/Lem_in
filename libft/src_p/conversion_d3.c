/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_d3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:45:11 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:57:38 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	void	conversion_d4(t_format *arg)
{
	if (!(arg->res = ft_memalloc(arg->width + 1)))
		exit(-1);
	if (ft_strchr(arg->option, '0') != 0 && ft_strchr(arg->option, '-') == 0
		&& arg->precision == 0 && ft_strchr(arg->str, '.') == 0)
		ft_memset(arg->res, '0', arg->width);
	else
		ft_memset(arg->res, ' ', arg->width);
}

static	void	conversion_d4_f(t_format *arg)
{
	if (!(arg->res = ft_memalloc(arg->width + 1)))
		exit(-1);
	if (ft_strchr(arg->option, '0') != 0 && ft_strchr(arg->option, '-') == 0)
		ft_memset(arg->res, '0', arg->width);
	else
		ft_memset(arg->res, ' ', arg->width);
}

static	void	conversion_d3_1(t_format *arg, char *nb, int len_nb)
{
	int i;

	i = 0;
	if ((nb[0] == '-' || nb[0] == '+') && ft_strchr(arg->option, '0') != 0
			&& arg->precision == 0 && ft_strchr(arg->str, '.') == 0)
		arg->res[i++] = nb[0];
	else if ((arg->type == 'x' || arg->type == 'X')
				&& ft_strchr(arg->option, '#') != 0
				&& ft_strchr(arg->option, '0') != 0
				&& ft_strchr(arg->str, '.') == 0
				&& ft_strcmp(nb, "0") != 0)
	{
		arg->res[i++] = nb[0];
		arg->res[i++] = nb[1];
	}
	while (nb[i])
	{
		arg->res[arg->width - len_nb + i] = nb[i];
		i++;
	}
}

void			conversion_d3(t_format *arg, char *nb, int len_nb)
{
	int i;

	i = 0;
	if (arg->type != 'f' && arg->type != 'F')
		conversion_d4(arg);
	else
		conversion_d4_f(arg);
	if (ft_strchr(arg->option, '-') != 0)
		while (nb[i])
		{
			arg->res[i] = nb[i];
			i++;
		}
	else
		conversion_d3_1(arg, nb, len_nb);
}
