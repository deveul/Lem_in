/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 12:50:41 by smakni            #+#    #+#             */
/*   Updated: 2019/03/05 23:34:55 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static	void	clean_flow(t_env *env)
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

static	void	reset_paths(t_env *env)
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
/*
   static	int		cpy_tmp_init(t_env *env, t_path tmp)
   {
   t_path		tmp_init;

   tmp_init.len = 0;
   tmp_init.path = NULL;
   tmp_init = tmp;
   tmp_init.path = ft_memalloc(sizeof(int) * (tmp.len + 1));
   ft_memcpy(tmp_init.path, tmp.path, sizeof(int) * (tmp.len + 1));
   add_result(&env->results, tmp_init);
   return (1);
   }
   */
static	void	update_flow(t_path tmp, t_env *env)
{
	int i;

	i = 0;
	while (i <= tmp.len)
	{
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
			if (env->rooms[tmp.path[i]].v_in != -1 && env->rooms[tmp.path[i]].v_out != -1)
				env->rooms[tmp.path[i]].capacity = 1;
			else
				env->rooms[tmp.path[i]].capacity = 0;
		}
		i++;
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
		i = 0;
		while (i < env->nb_nodes)
		{
			if (!(env->best_flow[i] = ft_memalloc(sizeof(int) * env->nb_nodes)))
				exit(-1);
			i++;
		}
	}
	i = 0;
	while (i < env->nb_nodes)
	{
		j = 0;
		while (j < env->nb_nodes)
		{
			env->best_flow[i][j] = env->flow[i][j];
			j++;
		}
		i++;
	}
}

int				edmonds_karp(t_env *env)
{
	t_path		tmp;
	int			trigger;
	int			i;
	int			tmp_nb_line;
	int			save;

	tmp.len = 0;
	trigger = 0;
	tmp_nb_line = INFINITE;
	save = INFINITE;
	env->best_flow = NULL;
	i = 0;
	while (tmp.len != -1)
	{
		tmp = bfs(env);
		//		if (trigger == 0 && tmp.len > env->nb_ants)
		//			trigger = cpy_tmp_init(env, tmp);
		//		else if (trigger == 0)
		trigger = 2;
		update_flow(tmp, env);
		reset_paths(env);
		bfs_second(env, env->flow);
		tmp_nb_line = calculate_line(env);
		if (save > tmp_nb_line)
		{
			save_flow(env);
			save = tmp_nb_line;
		}
		else
		{
			reset_paths(env);
			break;
		}
		reset_paths(env);
		i++;
	}
	clean_flow(env);
	return (trigger);
}
