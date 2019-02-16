/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:01:30 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/16 14:16:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		create_matrice(t_env *env)
{
	int		i;
	int 	j;

	j = 0;
	i = 0;
	if (!(env->matrice = ft_memalloc(sizeof(int*) * env->nb_nodes)))
		exit (-1);
	while (i < env->nb_nodes)
	{
		if (!(env->matrice[i] = ft_memalloc(sizeof(int) * env->nb_nodes)))
			exit (-1);
		j = 0;
		while (j < env->nb_nodes)
			env->matrice[i][j++] = 9999;
		i++;
	}
	return (1);
}
