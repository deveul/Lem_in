/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:01:30 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/08 16:55:50 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		create_matrice(t_env *env)
{
	int		i;

	i = 0;
	if (!(env->matrice = ft_memalloc(sizeof(int*) * env->nb_nodes)))
		return (-1);
	while (i < env->nb_nodes)
	{
		if (!(env->matrice[i] = ft_memalloc(sizeof(int) * env->nb_nodes)))
			return (-1);
		i++;
	}
	return (1);
}
