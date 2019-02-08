/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:57:29 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/08 15:36:02 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	print_matrice(t_env *env)
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
		ft_printf ("\t[%.4d]", env->rooms[i].index);
		ft_printf ("%-10s ", env->rooms[i].name);
		if (env->rooms[i].start == 1)
			ft_printf("\tstarting node");
		if (env->rooms[i].end == 1)
			ft_printf("\tending node");
		ft_putendl("");
		i++;
	}
	ft_putendl("");
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
		j = 0;
		while (j < env->rooms[i].nb_edges)
		{
			//ft_printf("\tconnected with node : %s", env->rooms[i].edges[j]);
			ft_printf("\t [%d]\n", env->rooms[env->rooms[i].connexion[j]].index);
			j++;
		}
		i++;
	}
	print_matrice(env);
}
