/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:41:57 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:57:38 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int				check_precision(char *str)
{
	int		i;
	char	*tmp;
	int		start;
	int		precision;

	i = 0;
	start = 0;
	if (ft_strchr(str, '.') == 0)
		return (0);
	while (str[start] != '.')
		start++;
	start++;
	if (str[start + 1] < '0' && str[start + 1] > '9')
		return (1);
	while (str[start + i] >= '0' && str[start + i] <= '9')
		i++;
	tmp = ft_strsub(str, start, i);
	precision = ft_atoi(tmp);
	ft_strdel(&tmp);
	return (precision);
}

int				check_str(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '#' || str[i] == '+' || str[i] == '-'
			|| str[i] == '0')
		i++;
	while (str[i] && str[i] != '.')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

char			*check_size(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == 'h')
			count++;
		i++;
	}
	if (ft_strchr(str, 'l') != 0 || ft_strchr(str, 'j') != 0
			|| ft_strchr(str, 'z') != 0)
		return ("l");
	else if (count >= 2)
		return ("hh");
	else if (count == 1)
		return ("h");
	return ("");
}
