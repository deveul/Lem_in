/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_x1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:15:36 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:57:38 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static	char	*x1_1(char *x, char *nb)
{
	if (!(x = ft_memalloc(3 + ft_strlen(nb))))
		exit(-1);
	x[0] = '0';
	x[1] = 'x';
	x[2] = '\0';
	return (x = ft_strcat(x, nb));
}

static	char	*x1_2(char *bx, char *nb)
{
	if (!(bx = ft_memalloc(3 + ft_strlen(nb))))
		exit(-1);
	bx[0] = '0';
	bx[1] = 'X';
	bx[2] = '\0';
	return (bx = ft_strcat(bx, nb));
}

char			*conversion_x1(t_format *arg, char *nb)
{
	char *x;
	char *bx;

	if (ft_strcmp(nb, "0") == 0)
		return (ft_strdup("0"));
	x = NULL;
	bx = NULL;
	if (arg->type == 'x')
	{
		x = x1_1(x, nb);
		ft_strdel(&nb);
		nb = ft_strdup(x);
		ft_strdel(&x);
	}
	else if (arg->type == 'X')
	{
		bx = x1_2(bx, nb);
		ft_strdel(&nb);
		nb = ft_strdup(bx);
		ft_strdel(&bx);
	}
	return (nb);
}
