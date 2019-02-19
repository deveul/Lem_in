/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 13:12:50 by smakni            #+#    #+#             */
/*   Updated: 2019/02/19 11:10:01 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_revsort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int s;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < (size - 1))
		{
			if (tab[j] < tab[j + 1])
			{
				s = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = s;
			}
			j++;
		}
		i++;
	}
}
