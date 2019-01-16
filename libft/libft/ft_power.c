/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:37:42 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/09/20 16:54:17 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int nb, int power)
{
	int		save;

	save = nb;
	if (power == 0)
		return (1);
	while (power > 1)
	{
		nb = nb * save;
		power--;
	}
	return (nb);
}
