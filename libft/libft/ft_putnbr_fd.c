/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:25:14 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/04/18 15:21:01 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_is_min(int fd)
{
	ft_putchar_fd('-', fd);
	ft_putchar_fd('2', fd);
	return (147483648);
}

static int	ft_n_is_negative(int n, int fd)
{
	ft_putchar_fd('-', fd);
	return (-n);
}

void		ft_putnbr_fd(int n, int fd)
{
	int		size;
	int		save;
	int		cpt;

	size = 1;
	cpt = 1;
	if (n == -2147483648)
		n = ft_n_is_min(fd);
	if (n < 0)
		n = ft_n_is_negative(n, fd);
	save = n;
	while (n > 9)
	{
		n = n / 10;
		size = size * 10;
		cpt++;
	}
	while (cpt > 0)
	{
		n = save;
		n = (n / size) % 10;
		size = size / 10;
		ft_putchar_fd((n + 48), fd);
		cpt--;
	}
}
