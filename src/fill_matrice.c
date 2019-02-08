/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:01:30 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/05 18:41:39 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void	check_connexion(t_env *env, int i, int j)
{
	int		k;

	k = 0;
	env->matrice[i][j] = 0;
	while (k < env->rooms[i].nb_edges)
	{
		if (env->rooms[i].connexion[k] == j)
			env->matrice[i][j] = 1;
		k++;
	}
}

int		fill_matrice(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	if (!(env->matrice = ft_memalloc(sizeof(int*) * env->nb_nodes)))
		return (-1);
	while (i < env->nb_nodes)
	{
		j = 0;
		if (!(env->matrice[i] = ft_memalloc(sizeof(int) * env->nb_nodes)))
			return (-1);
		while (j < env->nb_nodes)
		{
			check_connexion(env, i, j);
			j++;
		}
		i++;
	}
	return (1);
}
