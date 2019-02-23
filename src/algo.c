/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 11:19:42 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/23 12:09:36 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void	clean_flow(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->nb_nodes)
	{
		j = 0;
		while (j < env->nb_nodes)
		{
			if (env->flow[i][j] == -1)
			{
				env->flow[i][j] = INFINITE;
				env->flow[j][i] = INFINITE;
			}
			else if (env->flow[i][j] == 0)
				env->flow[i][j] = INFINITE;
			j++;
		}
		i++;
	}
}

static void	reset_paths(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->nb_path)
	{
		free(env->paths[i].path);
		i++;
	}
	free(env->paths);
	free(env->fifo);
	i = 0;
	while (i < env->nb_nodes)
	{
		env->rooms[i].check = 0;
		i++;
	}
	env->nb_path = 0;
	env->nb_fifo = 0;
	env->end_found = 0;
}

static void	edmonds_karp(t_env *env)
{
	t_path		tmp;
	int			i;

	tmp.len = 0;
	while (tmp.len != -1)
	{
//		ft_printf("ta soeur\n");
		tmp = bfs(env);
		i = 0;
		while (i <= tmp.len)
		{
			if (i < tmp.len && env->flow[tmp.path[i]][tmp.path[i + 1]] == 0
					&& env->flow[tmp.path[i + 1]][tmp.path[i]] != 1)
				env->flow[tmp.path[i]][tmp.path[i + 1]] = 1;
			else if (i < tmp.len)
				env->flow[tmp.path[i]][tmp.path[i + 1]] = -1;
			i++;
		}
		reset_paths(env);
	}
	clean_flow(env);
}

int			analyze_graph(t_env *env)
{
	int		i;
	
	init_flow(env);
	if (env->start_nb >= 1 && env->end_nb >= 1)
		edmonds_karp(env);
	i = 0;
	while (i < env->start_nb)
	{
		dijkstra(env, env->nb_nodes);
		i++;
	}
//	ft_printf(">>>>>>>>>>>>>>>>>END_SEARCH<<<<<<<<<<<<<<<<<<<<\n\n");
	if (env->nb_path > 0)
	{
		create_path_tab(env->results, &env->paths, env->nb_path);
//		print_path(env);
	}
	if (env->nb_path == 0)
	{
		ft_putendl("No passaran");
		return (-1);
	}	
	return (0);
}
