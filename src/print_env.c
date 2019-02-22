/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:57:29 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/22 18:57:17 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	print_path_with_name(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	ft_putendl(">>>>>>>>>>>Paths with name<<<<<<<<<<<<<<<");
	while (i < env->nb_path)
	{
		ft_putendl("");
		ft_printf("Path[%2d]: ", i);
		j = 0;
		while (j < env->paths[i].len)
		{
			ft_printf("%-10s", env->rooms[env->paths[i].path[j]].name);
			j++;
		}
		ft_putendl("");
		i++;
	}
	ft_putendl("");
}

void	print_path(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	ft_putendl(">>>>>>>>>>>Paths<<<<<<<<<<<<<<<");
	while (i < env->nb_path)
	{
		ft_putendl("");
		ft_printf("Path[%2d]: ", i);
		j = 0;
		while (j < env->paths[i].len)
		{
			ft_printf("%-5d", env->paths[i].path[j]);
			j++;
		}
		ft_putendl("");
		i++;
	}
	ft_putendl("");
	print_path_with_name(env);
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

void	print_flow(t_env *env)
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
				ft_printf("%4d |", env->flow[i][j]);
			else if (j < env->nb_nodes - 1)
				ft_printf(" %4d |", env->flow[i][j]);
			else
				ft_printf(" %4d", env->flow[i][j]);
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
