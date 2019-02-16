/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:33:26 by smakni            #+#    #+#             */
/*   Updated: 2019/02/08 19:12:48 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	dequeue_one_fifo(t_env *env)
{
	int		i;
	int		j;
	int		tmp_index;
	int		tmp_i_p;

	i = 1;
	j = 0;
	tmp_index = env->fifo[0].index;
	tmp_i_p = env->fifo[0].path_index;
	while (i < env->nb_fifo)
		env->fifo[j++] = env->fifo[i++];
	if (env->paths[tmp_i_p].end_found == 0)
	{
		if (!(env->paths[tmp_i_p].path = expand_table(env->paths[tmp_i_p].path,
						env->paths[tmp_i_p].len++, tmp_index)))
			return (-1);
		if (tmp_index == env->end_index)
		{
			env->paths[tmp_i_p].end_found = 1;
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
						env->nb_path, tmp.path_index)))
			return (-1);
		env->fifo[env->nb_fifo].path_index = env->nb_path++;
	}
	env->nb_fifo++;
	return (0);
}

static int	while_fifo(t_env *env, int i, int nb_path_needed)
{
	t_fifo	tmp;

	while (env->nb_fifo != 0)
	{
		tmp = env->fifo[0];
		if (dequeue_one_fifo(env) == -1)
			return (-1);
		i = -1;
		nb_path_needed = 0;
		while (++i < env->nb_nodes)
			if (env->matrice[tmp.index][i] == 1 && env->rooms[i].check == 0)
				if (enqueue_fifo(env, i, &nb_path_needed, tmp) == -1)
					return (-1);
	}
	return (0);
}

int			algo(t_env *env)
{
	int		i;
	int		nb_path_needed;

	i = 0;
	nb_path_needed = 0;
	while (i < env->nb_nodes)
	{
		if (env->matrice[env->start_index][i] == 1)
			env->nb_path++;
		i++;
	}
	if (!(env->paths = ft_memalloc(sizeof(t_path) * env->nb_path)))
		return (-1);
	env->nb_fifo = env->nb_path;
	if (init_paths(env) == -1)
		return (-1);
	if (!(env->fifo = ft_memalloc(sizeof(t_fifo) * env->nb_nodes)))
		return (-1);
	fill_initial_fifo(env);
	if (while_fifo(env, i, nb_path_needed) == -1)
		return (-1);
	print_path(env);
	return (0);
}
