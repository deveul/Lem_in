/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_bs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 14:59:36 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:57:38 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int				check_error_c(unsigned c)
{
	if ((c >= 55296 && c <= 57343) || c > 1114111)
		return (-1);
	else if (c <= 127)
		return (1);
	else if (c < 256 && MB_CUR_MAX == 1)
		return (1);
	else if (c <= 2047 && MB_CUR_MAX >= 2)
		return (2);
	else if (c <= 65536 && MB_CUR_MAX >= 3)
		return (3);
	else if (c < 1114111 && MB_CUR_MAX >= 4)
		return (4);
	return (-1);
}

static int		len(unsigned c)
{
	if (c <= 127)
		return (1);
	else if (c < 256)
		return (1);
	else if (c <= 2047)
		return (2);
	else if (c <= 65536)
		return (3);
	else if (c < 1114111)
		return (4);
	else
		return (1);
}

static	char	*get_c(char *ret, wchar_t c, int x)
{
	char *tmp_c;

	if (!(tmp_c = ft_memalloc(x + 1)))
		exit(-1);
	tmp_c = ft_putchar_printf(c, tmp_c, x);
	ret = ft_strjoin_free(ret, tmp_c);
	return (ret);
}

char			*conversion_bs(t_format *arg, va_list av)
{
	wchar_t	*tmp;
	int		x;
	int		i;
	int		stop;
	char	*ret;

	i = 0;
	x = 0;
	stop = 0;
	if ((tmp = va_arg(av, wchar_t *)) == NULL)
		return (NULL);
	if (!(ret = ft_memalloc(1)))
		exit(-1);
	while (tmp[i])
	{
		if ((stop += (x = len(tmp[i]))) > arg->precision && arg->precision > 0)
			break ;
		if (check_error_c(tmp[i]) == -1)
		{
			arg->check = -1;
			break ;
		}
		ret = get_c(ret, tmp[i++], x);
	}
	return (ret);
}
