/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:41:00 by sabri             #+#    #+#             */
/*   Updated: 2018/12/05 09:57:38 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	char	*conversion_s0(t_format *arg, char *tmp, va_list av)
{
	if ((arg->type == 's' && ft_strcmp(arg->size, "l") == 0)
			|| arg->type == 'S')
		tmp = conversion_bs(arg, av);
	else if ((tmp = va_arg(av, char *)) != NULL)
		tmp = ft_strdup(tmp);
	return (tmp);
}

static	char	*conversion_s1(t_format *arg, char *tmp)
{
	int i;

	i = 0;
	while (tmp[i] && i < arg->precision)
		i++;
	tmp = ft_strsub(tmp, 0, i);
	return (tmp);
}

static	char	*conversion_s2(t_format *arg, char *tmp, int len, int i)
{
	if (!(arg->res = ft_memalloc(arg->width + 1)))
		exit(-1);
	if (ft_strchr(arg->option, '0') != 0 && ft_strchr(arg->option, '-') == 0)
		ft_memset(arg->res, '0', arg->width);
	else
		ft_memset(arg->res, ' ', arg->width);
	if (ft_strchr(arg->option, '-') != 0)
		while (tmp[i])
		{
			arg->res[i] = tmp[i];
			i++;
		}
	else
		while (tmp[i])
		{
			arg->res[arg->width - len + i] = tmp[i];
			i++;
		}
	return (arg->res);
}

static	void	conversion_s3(t_format *arg, char *tmp, int len)
{
	int i;

	i = 0;
	if ((ft_strcmp(tmp, "(null)")) == 0 && arg->width > 0
			&& ft_strchr(arg->str, '.') != 0)
		tmp = ft_strdup("");
	if (arg->width > len || ((ft_strcmp(tmp, "")) == 0 && arg->width > 0))
		arg->res = conversion_s2(arg, tmp, len, i);
	else
		arg->res = ft_strdup(tmp);
}

void			conversion_s(t_format *arg, va_list av)
{
	char	*tmp;
	int		len;

	tmp = NULL;
	tmp = conversion_s0(arg, tmp, av);
	if (arg->precision == 0 && ft_strchr(arg->str, '.') != 0 && arg->width == 0)
	{
		arg->res = ft_strdup("");
		arg->count = 0;
		ft_strdel(&tmp);
		return ;
	}
	if (tmp == NULL || (arg->precision == 0 && ft_strchr(arg->str, '.') != 0))
		tmp = ft_strdup("(null)");
	len = ft_strlen(tmp);
	if (arg->type == 's' && ft_strcmp(arg->size, "") == 0
			&& arg->precision < len && arg->precision != 0)
	{
		tmp = conversion_s1(arg, tmp);
		len = ft_strlen(tmp);
	}
	conversion_s3(arg, tmp, len);
	ft_strdel(&tmp);
	arg->count = ft_strlen(arg->res);
}
