/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:57:29 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/13 17:52:44 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	print_path(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	ft_putendl(">>>>>>>>>>>Paths<<<<<<<<<<<<<<<");
	while (i < env->nb_path)
	{
		ft_printf("Path [%4d]: ", i);
		j = 0;
		while (j < env->paths[i].len)
		{
			ft_printf("%-7d", env->paths[i].path[j]);
			j++;
		}
		ft_putendl("");
		i++;
	}
	i = 0;
	ft_putendl("");
	ft_putendl(">>>>>>>>>>>Valid Paths<<<<<<<<<<<<<<<");
	while (i < env->nb_path)
	{
		if (env->paths[i].end_found == 1)
		{
			ft_printf("Path_bfs[%4d]: ", i);
			j = 0;
			while (j < env->paths[i].len)
			{
				if (j < env->paths[i]. len - 1)
					ft_printf("%s-", env->rooms[env->paths[i].path[j]].name);
				else
					ft_printf("%s", env->rooms[env->paths[i].path[j]].name);
				j++;
			}
			ft_putendl("");
		}
		i++;
	}
}

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
				ft_printf("-------");
			else
				ft_printf("-----");
			j++;
		}
		ft_putendl("");
		j = 0;
		while (j < env->nb_nodes)
		{
			if (j == 0)
				ft_printf("%4d |", env->matrice[i][j]);
			else if (j < env->nb_nodes - 1)
				ft_printf(" %4d |", env->matrice[i][j]);
			else
				ft_printf(" %4d", env->matrice[i][j]);
			j++;
		}
		ft_printf("\t[%04d]", env->rooms[i].index);
		ft_printf("\t%-10s ", env->rooms[i].name);
		if (env->rooms[i].start == 1)
			ft_printf(">>>>>>>>[starting node]<<<<<<<<");
		if (env->rooms[i].end == 1)
			ft_printf(">>>>>>>>>[ending node]<<<<<<<<<");
		ft_putendl("");
		i++;
	}
	ft_putendl("");
}

void	print_env(t_env *env)
{
	ft_printf("Ants number : %ld\n\n", env->nb_ants);
	ft_printf("Nodes number : %d\n\n", env->nb_nodes);
	print_matrice(env);
}
