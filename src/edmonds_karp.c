/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 12:50:41 by smakni            #+#    #+#             */
/*   Updated: 2019/03/06 11:43:04 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		clean_flow(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->nb_nodes)
	{
		j = 0;
		while (j < env->nb_nodes)
		{
			if (env->flow[i][j] != 1)
				env->flow[i][j] = INFINITE;
			if (env->best_flow[i][j] != 1)
				env->best_flow[i][j] = INFINITE;
			j++;
		}
		i++;
	}
}

static void		update_flow(t_path tmp, t_env *env)
{
	int i;

	i = -1;
	while (++i <= tmp.len)
		if (i < tmp.len)
		{
			if (env->flow[tmp.path[i]][tmp.path[i + 1]] == -1)
			{
				env->flow[tmp.path[i]][tmp.path[i + 1]] = 0;
				env->flow[tmp.path[i + 1]][tmp.path[i]] = 0;
				env->rooms[tmp.path[i + 1]].v_out = 0;
				if (env->rooms[tmp.path[i]].v_out == 0)
					env->rooms[tmp.path[i]].v_in = 0;
			}
			else
			{
				env->flow[tmp.path[i]][tmp.path[i + 1]] = 1;
				env->flow[tmp.path[i + 1]][tmp.path[i]] = -1;
				env->rooms[tmp.path[i + 1]].v_in = tmp.path[i];
				env->rooms[tmp.path[i]].v_out = tmp.path[i + 1];
			}
			if (env->rooms[tmp.path[i]].v_in != -1
					&& env->rooms[tmp.path[i]].v_out != -1)
				env->rooms[tmp.path[i]].capacity = 1;
			else
				env->rooms[tmp.path[i]].capacity = 0;
		}
}

static void		save_flow(t_env *env)
{
	int		i;
	int		j;

	if (!env->best_flow)
	{
		if (!(env->best_flow = ft_memalloc(sizeof(int *) * env->nb_nodes)))
			exit(-1);
		i = -1;
		while (++i < env->nb_nodes)
			if (!(env->best_flow[i] = ft_memalloc(sizeof(int) * env->nb_nodes)))
				exit(-1);
	}
	i = -1;
	while (++i < env->nb_nodes)
	{
		j = -1;
		while (++j < env->nb_nodes)
			env->best_flow[i][j] = env->flow[i][j];
	}
}

void			edmonds_karp(t_env *env)
{
	t_path		tmp;
	int			tmp_nb_line;
	int			save;

	tmp.len = 0;
	tmp_nb_line = INFINITE;
	save = INFINITE;
	env->best_flow = NULL;
	while (tmp.len != -1)
	{
		reset_paths(env);
		tmp = bfs(env);
		update_flow(tmp, env);
		reset_paths(env);
		bfs_second(env, env->flow);
		if (save > (tmp_nb_line = calculate_line(env)))
		{
			save_flow(env);
			save = tmp_nb_line;
		}
		else
			break ;
	}
	clean_flow(env);
}
