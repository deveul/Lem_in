/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 13:07:08 by sabri             #+#    #+#             */
/*   Updated: 2018/12/05 09:57:38 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	int	get_len_x(unsigned nb)
{
	int i;

	i = 0;
	while (nb != 0)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

void		conversion_x(t_format *arg, va_list av)
{
	unsigned int	nb;
	int				tmp;
	int				i;

	nb = va_arg(av, int);
	tmp = nb;
	i = get_len_x(nb);
	if (!(arg->res = ft_memalloc(i + 1)))
		exit(-1);
	while (nb != 0)
	{
		i--;
		tmp = nb % 16;
		if (tmp < 10)
			tmp = tmp + 48;
		else
			tmp = tmp + 87;
		arg->res[i] = tmp;
		nb = nb / 16;
	}
	arg->count = ft_strlen(arg->res);
}

void		conversion_bx(t_format *arg, va_list av)
{
	unsigned int	nb;
	int				tmp;
	int				i;

	nb = va_arg(av, int);
	tmp = nb;
	i = get_len_x(nb);
	if (!(arg->res = ft_memalloc(i + 1)))
		exit(-1);
	while (nb != 0)
	{
		i--;
		tmp = nb % 16;
		if (tmp < 10)
			tmp = tmp + 48;
		else
			tmp = tmp + 55;
		arg->res[i] = tmp;
		nb = nb / 16;
	}
	arg->count = ft_strlen(arg->res);
}
