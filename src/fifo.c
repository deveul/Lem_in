/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:19:07 by smakni            #+#    #+#             */
/*   Updated: 2019/03/04 19:42:05 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static	void	dequeue_one_fifo(t_env *env)
{
	int		i;
	int		j;
	int		len;
	int		tmp_index;
	int		tmp_i_p;
	int		tmp_from;

	i = 1;
	j = 0;
	tmp_index = env->fifo[0].index;
	tmp_i_p = env->fifo[0].path_index;
	tmp_from = env->fifo[0].from;
	len = env->paths[tmp_i_p].len;
	while (i < env->nb_fifo)
		env->fifo[j++] = env->fifo[i++];
	env->nb_fifo--;
	env->paths[tmp_i_p].len++;
	env->paths[tmp_i_p].path[len] = tmp_index;
	if (tmp_index == env->end_index)
	{
		env->paths[tmp_i_p].end_found = 1;
		env->end_found = 1;
		env->nb_path_ok++;
	}
	if (env->rooms[tmp_index].capacity == 1 && tmp_from == 0)
		env->flow_to_find = -1;
	else if (env->rooms[tmp_index].capacity == 1 && tmp_from == -1)
		env->flow_to_find = 1;
	else
		env->flow_to_find = 0;
}

static void		enqueue_fifo(t_env *env, int i, int *nb_path_needed, t_fifo tmp, int from)
{
	env->fifo[env->nb_fifo].index = i;
	env->fifo[env->nb_fifo].from = from;
	if (i != env->end_index)
		env->rooms[i].check = 1;
	if (*nb_path_needed == 0)
	{
		env->fifo[env->nb_fifo].path_index = tmp.path_index;
		(*nb_path_needed)++;
	}
	else
	{
		add_path(env->paths, env->nb_path, tmp.path_index, env->nb_nodes);
		env->fifo[env->nb_fifo].path_index = env->nb_path++;
	}
	env->nb_fifo++;
}

int				while_fifo(t_env *env)
{
	int		i;
	int		nb_path_needed;
	t_fifo	tmp;

	env->flow_to_find = 0;
	while (env->nb_fifo != 0 && env->end_found == 0)
	{
		tmp = env->fifo[0];
		dequeue_one_fifo(env);
		if (env->end_found == 1)
			break ;
		i = 0;
		nb_path_needed = 0;
		while (i < env->nb_nodes)
		{
			if (env->flow_to_find == 0)
			{
				if (env->matrice[tmp.index][i] == 1 && env->rooms[i].check == 0
							&& env->flow[tmp.index][i] == 0)
					enqueue_fifo(env, i, &nb_path_needed, tmp, 0);
			}
			else if (env->flow_to_find == -1)
			{
				if (env->matrice[tmp.index][i] == 1 && env->rooms[i].check == 0
							&& env->flow[tmp.index][i] == -1)
					enqueue_fifo(env, i, &nb_path_needed, tmp, -1);
			}
			else if (env->flow_to_find == 1)
			{
				if (env->matrice[tmp.index][i] == 1 && env->rooms[i].check == 0
							&& (env->flow[tmp.index][i] == -1 || env->flow[tmp.index][i] == 0))
					enqueue_fifo(env, i, &nb_path_needed, tmp, env->flow[tmp.index][i]);
			}
			i++;
		}
	}
	return (0);
}
