/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_d2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:26:18 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:57:38 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	char	*conversion_d2_1(t_format *arg, char *tmp, char *nb)
{
	int i;

	i = 0;
	if (!(tmp = ft_memalloc(arg->precision + 2)))
		exit(-1);
	ft_memset(tmp, '0', arg->precision);
	tmp[0] = nb[0];
	i++;
	while (nb[i])
	{
		tmp[arg->precision + 1 - ft_strlen(nb) + i] = nb[i];
		i++;
	}
	return (tmp);
}

static	char	*conversion_d2_2(t_format *arg, char *tmp, char *nb)
{
	int i;

	i = 0;
	if (!(tmp = ft_memalloc(arg->precision + 1)))
		exit(-1);
	ft_memset(tmp, '0', arg->precision);
	while (nb[i])
	{
		tmp[arg->precision - ft_strlen(nb) + i] = nb[i];
		i++;
	}
	return (tmp);
}

char			*conversion_d2(t_format *arg, char *nb)
{
	char	*tmp;

	tmp = NULL;
	if (nb[0] == '-' || nb[0] == '+')
	{
		tmp = conversion_d2_1(arg, tmp, nb);
		ft_strdel(&nb);
		nb = tmp;
	}
	else
	{
		tmp = conversion_d2_2(arg, tmp, nb);
		ft_strdel(&nb);
		nb = tmp;
	}
	return (nb);
}

char			*conversion_d2x(t_format *arg, char *nb)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(tmp = ft_memalloc(arg->precision + 3)))
		exit(-1);
	ft_memset(tmp, '0', arg->precision);
	tmp[0] = '0';
	if (arg->type == 'x')
		tmp[1] = 'x';
	else
		tmp[1] = 'X';
	while (nb[i])
	{
		tmp[arg->precision - ft_strlen(nb) + i + 2] = nb[i];
		i++;
	}
	ft_strdel(&nb);
	nb = tmp;
	return (nb);
}
