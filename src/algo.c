/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:33:26 by smakni            #+#    #+#             */
/*   Updated: 2019/02/22 19:41:21 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	dequeue_one_fifo(t_env *env)
{
	int		i;
	int		j;
	int		len;
	int		tmp_index;
	int		tmp_i_p;

	i = 1;
	j = 0;
	tmp_index = env->fifo[0].index;
	tmp_i_p = env->fifo[0].path_index;
	len = env->paths[tmp_i_p].len;
	while (i < env->nb_fifo)
		env->fifo[j++] = env->fifo[i++];
	if (env->paths[tmp_i_p].end_found == 0)
	{
		env->paths[tmp_i_p].len++;
		env->paths[tmp_i_p].path[len] = tmp_index;
		if (tmp_index == env->end_index)
		{
			env->paths[tmp_i_p].end_found = 1;
			env->end_found = 1;
			env->nb_path_ok++;
		}
	}
	env->nb_fifo--;
	return (0);
}

static int	enqueue_fifo(t_env *env, int i, int *nb_path_needed, t_fifo tmp)
{
	env->fifo[env->nb_fifo].index = i;
	if (i != env->end_index)
		env->rooms[i].check = 1;
	if (*nb_path_needed == 0)
	{
		env->fifo[env->nb_fifo].path_index = tmp.path_index;
		(*nb_path_needed)++;
	}
	else
	{
		if (!(env->paths = add_path(env->paths,
						env->nb_path, tmp.path_index, env->nb_nodes)))
			return (-1);
		env->fifo[env->nb_fifo].path_index = env->nb_path++;
	}
	env->nb_fifo++;
	return (0);
}

static int	while_fifo(t_env *env, int i, int nb_path_needed)
{
	t_fifo	tmp;

	while (env->nb_fifo != 0 && env->end_found == 0)
	{
		tmp = env->fifo[0];
		if (dequeue_one_fifo(env) == -1)
			return (-1);
		if (env->end_found == 1)
			break ;
		i = 0;
		nb_path_needed = 0;
		while (i < env->nb_nodes)
		{
			if (env->matrice[tmp.index][i] == 1 && env->rooms[i].check == 0 && env->flow[tmp.index][i] == 0)
			{
				if (enqueue_fifo(env, i, &nb_path_needed, tmp) == -1)
					return (-1);
			}
			i++;
		}
	}
	return (0);
}

t_path		bfs(t_env *env)
{
	int		i;
	int		save;
	int		nb_path_needed;
	t_path	not_found;

	i = 0;
	save = -1;
	nb_path_needed = 0;
	env->end_found = 0;
	while (i < env->nb_nodes)
	{
		if (env->matrice[env->start_index][i] == 1 && env->flow[env->start_index][i] == 0)
			env->nb_path++;
		i++;
	}
	if (!(env->paths = ft_memalloc(sizeof(t_path) * env->nb_path)))
		exit(-1);
	env->nb_fifo = env->nb_path;
	if (init_paths(env) == -1)
		exit(-1);
	if (!(env->fifo = ft_memalloc(sizeof(t_fifo) * env->nb_nodes)))
		exit(-1);
	fill_initial_fifo(env);
	if (while_fifo(env, i, nb_path_needed) == -1)
		exit(-1);
	i = 0;
	while (i < env->nb_path)
	{
		if (env->paths[i].end_found == 1)
			save = i;
		env->paths[i].len--;
		i++;
	}
	if (save == -1)
	{
		not_found.len = -1;
		return (not_found);
	}
	return (env->paths[save]);
}

void		clean_flow(t_env *env)
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

void		edmonds_karp(t_env *env)
{
	t_path		tmp;
	int			i;

	tmp.len = 0;
	while (tmp.len != -1)
	{
		ft_printf("ta soeur\n");
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
