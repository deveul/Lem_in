/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_useful.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:05:41 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/31 16:27:07 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_del_prfo(t_prf *prf)
{
	ft_strdel(&prf->top);
	ft_strdel(&prf->tmp);
	ft_strdel(&prf->tmp2);
}

void	ft_del_prf2(t_prf *prf, t_fmt *arg)
{
	ft_strdel(&prf->top);
	ft_strdel(&prf->tmp);
	ft_strdel(&prf->tmp2);
	ft_strdel(&arg->size);
}

void	ft_del_prf(t_prf *prf, t_fmt *arg)
{
	ft_strdel(&prf->tmp);
	ft_strdel(&prf->tmp2);
	ft_strdel(&arg->size);
}

int		ft_get_arg_nb(const char *fmt)
{
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1])
		{
			i++;
			while (fmt[i] && !ft_strchr("sSpdDioOuUxXcC%", fmt[i]))
				i++;
			cpt++;
		}
		if (fmt[i])
			i++;
	}
	return (cpt);
}

int		ft_only_fmt(int fd, const char *fmt)
{
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	while (fmt[i])
	{
		if (fmt[i] != '%')
		{
			write(fd, &fmt[i++], 1);
			cpt++;
		}
		else
			i++;
	}
	return (cpt);
}
