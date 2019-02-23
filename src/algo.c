/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 11:19:42 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/23 17:03:00 by vrenaudi         ###   ########.fr       */
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
			if (env->flow[i][j] == -1 && env->flow[j][i] == 1)
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

static int	cpy_tmp_init(t_env *env, t_path tmp)
{
	t_path		tmp_init;

	tmp_init.len = 0;
	tmp_init.path = NULL;
	tmp_init = tmp;
	tmp_init.path = ft_memalloc(sizeof(int) * (tmp.len + 1));
	ft_memcpy(tmp_init.path, tmp.path, sizeof(int) * (tmp.len + 1));
	if (tmp_init.len > env->nb_ants)
	{
		add_result(&env->results, tmp_init);
		return (1);
	}
	return (-1);
}

static int edmonds_karp(t_env *env)
{
	t_path		tmp;
	int			i;
	int			save;
	int			trigger;

	tmp.len = 0;
	trigger = 0;
	save = 0;
	while (tmp.len != -1)
	{
		tmp = bfs(env);
		if (trigger == 0)
			trigger = cpy_tmp_init(env, tmp);
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
	return (trigger);
}

int			analyze_graph(t_env *env)
{
	int		i;
	int		trigger;

	init_flow(env);
	if (env->start_nb >= 1 && env->end_nb >= 1)
		trigger = edmonds_karp(env);
	i = 0;
	while (i < env->start_nb)
	{
		dijkstra(env, env->nb_nodes);
		i++;
	}
	if (env->nb_path > 0)
	{
		if (trigger == 1)
			env->nb_path++;
		create_path_tab(env->results, &env->paths, env->nb_path);
		print_path(env);
	}
	if (env->nb_path == 0)
	{
		ft_putendl("No passaran");
		return (-1);
	}	
	return (0);
}
