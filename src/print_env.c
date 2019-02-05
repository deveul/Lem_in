/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:57:29 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/05 14:38:48 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void	print_matrice(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < env->nb_nodes)
	{
		j = 0;
		while (j < env->nb_nodes)
		{
			if (j != env->nb_nodes - 1)
				ft_printf("----");
			else
				ft_printf("--");
			j++;
		}
		ft_putendl("");
		j = 0;
		while (j < env->nb_nodes)
		{
			if (j == 0)
				ft_printf("%d |", env->matrice[i][j]);
			else if (j < env->nb_nodes - 1)
				ft_printf(" %d |", env->matrice[i][j]);
			else
				ft_printf(" %d", env->matrice[i][j]);
			j++;
		}
		ft_putendl("");
		i++;
	}
}

void		print_env(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	ft_printf("Ants number : %d\n\n", env->nb_ants);
	ft_printf("Nodes number : %d\n\n", env->nb_nodes);
	while (i < env->nb_nodes)
	{
		ft_printf ("node name : %s ", env->nodes[i].name);
		ft_printf ("| index : %d ", env->nodes[i].index);
		ft_printf ("| nb eges : %d\n[\n", env->nodes[i].nb_edges);
		j = 0;
		if (env->nodes[i].start == 1)
			ft_printf("\tstarting node\n");
		if (env->nodes[i].end == 1)
			ft_printf("\tending node\n");
		while (j < env->nodes[i].nb_edges)
		{
			ft_printf("\tconnected with node : %s", env->nodes[i].edges[j]);
			ft_printf("\t [%d]\n", env->nodes[env->nodes[i].connexion[j]].index);
			j++;
		}
		ft_printf("]\n");
		i++;
	}
	print_matrice(env);
}
