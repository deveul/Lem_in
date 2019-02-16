/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 23:12:30 by sabri             #+#    #+#             */
/*   Updated: 2018/12/05 09:57:38 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	char	*conversion_d1(t_format *arg, char *nb)
{
	char *tmp;

	if ((arg->type == 'd' || arg->type == 'D' || arg->type == 'i'
				|| arg->type == 'f' || arg->type == 'F')
			&& ft_strchr(arg->option, '+') != 0 && nb[0] != '-')
	{
		tmp = "+";
		nb = ft_strjoin_free(tmp, nb);
	}
	else if ((arg->type == 'o' || arg->type == 'O')
				&& ft_strchr(arg->option, '#') != 0
				&& nb[0] != '0')
	{
		tmp = "0";
		nb = ft_strjoin_free(tmp, nb);
	}
	return (nb);
}

static	int		conversion_null(t_format *arg, char *nb)
{
	int check;

	check = 0;
	if (nb[0] == '0' && ft_strchr(arg->str, '.') != 0
			&& arg->precision == 0 && arg->width == 0)
	{
		if (!(arg->res = ft_memalloc(1)))
			exit(-1);
		check = 1;
	}
	else if (ft_isdigit(nb[0]) == 0 && nb[1] == '0'
		&& ft_strchr(arg->str, '.') != 0 && arg->precision == 0
		&& arg->width == 0)
	{
		if (!(arg->res = ft_memalloc(2)))
			exit(-1);
		arg->res[0] = nb[0];
		check = 2;
	}
	return (check);
}

static	void	final(t_format *arg, char *tmp, char *nb, int len_nb)
{
	if ((arg->type == 'd' || arg->type == 'D' || arg->type == 'i')
		&& ft_strchr(arg->option, ' ') != 0
		&& arg->width <= len_nb && ft_isdigit(nb[0]) != 0)
	{
		if (!(tmp = ft_memalloc(2 + ft_strlen(arg->res))))
			exit(-1);
		tmp[0] = ' ';
		tmp[1] = '\0';
		tmp = ft_strcat(tmp, arg->res);
		ft_strdel(&arg->res);
		arg->res = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	else if (ft_strchr(arg->option, ' ') != 0
		&& ft_strchr(arg->option, '+') == 0 && arg->width > len_nb)
		arg->res[0] = ' ';
	arg->count = ft_strlen(arg->res);
	ft_strdel(&nb);
}

static	char	*empty_conv(char *nb)
{
	ft_strdel(&nb);
	nb = ft_strdup("");
	return (nb);
}

void			conversion_d(t_format *arg, va_list av)
{
	int		len_nb;
	char	*nb;
	char	*tmp;
	int		check;

	check = 0;
	tmp = NULL;
	nb = NULL;
	nb = conversion_d0(arg, nb, av);
	nb = conversion_d1(arg, nb);
	check = conversion_null(arg, nb);
	if (check == 0 && ft_strcmp(nb, "0") == 0 && arg->precision == 0
			&& ft_strchr(arg->str, '.') != 0)
		nb = empty_conv(nb);
	if (arg->precision >= (len_nb = ft_strlen(nb)))
		nb = conversion_d2(arg, nb);
	if (ft_strcmp(nb, "") != 0 && ft_strchr(arg->option, '#') != 0)
		nb = conversion_x1(arg, nb);
	if (arg->width > (len_nb = ft_strlen(nb)))
		conversion_d3(arg, nb, len_nb);
	else if (check == 0 || ((arg->type == 'o' || arg->type == 'O')
			&& ft_strchr(arg->option, '#') != 0))
		arg->res = ft_strdup(nb);
	final(arg, tmp, nb, len_nb);
}
