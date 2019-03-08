/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:57:29 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/07 14:39:40 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	print_data(char **data, int nb_line)
{
	int		i;

	i = 0;
	while (i < nb_line)
	{
		ft_putendl(data[i]);
		ft_strdel(&data[i]);
		i++;
	}
	ft_putendl("");
	free(data);
}
