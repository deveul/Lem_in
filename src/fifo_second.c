/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:19:07 by smakni            #+#    #+#             */
/*   Updated: 2019/03/04 14:45:49 by vrenaudi         ###   ########.fr       */
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

	i = 1;
	j = 0;
	tmp_index = env->fifo[0].index;
	tmp_i_p = env->fifo[0].path_index;
	len = env->prepaths[tmp_i_p].len;
	while (i < env->nb_fifo)
		env->fifo[j++] = env->fifo[i++];
	if (env->prepaths[tmp_i_p].end_found == 0)
	{
		env->prepaths[tmp_i_p].len++;
		env->prepaths[tmp_i_p].path[len] = tmp_index;
		if (tmp_index == env->end_index)
		{
			env->prepaths[tmp_i_p].end_found = 1;
			env->end_found++;
			env->nb_path_ok++;
		}
	}
	env->nb_fifo--;
}

static	int		enqueue_fifo(t_env *env, int i, int *nb_path_needed, t_fifo tmp)
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
		add_path(env->prepaths, env->nb_path, tmp.path_index, env->nb_nodes);
		env->fifo[env->nb_fifo].path_index = env->nb_path++;
	}
	env->nb_fifo++;
	return (0);
}

int				while_fifo_second(t_env *env, int nb_path_needed)
{
	int		i;
	t_fifo	tmp;

	while (env->nb_fifo != 0)
	{
		tmp = env->fifo[0];
		dequeue_one_fifo(env);
//		if (env->end_found == 1)
//			break ;
		i = 0;
		nb_path_needed = 0;
		while (i < env->nb_nodes)
		{
			if (env->flow[tmp.index][i] == 1 && env->rooms[i].check == 0)
			{
				if (enqueue_fifo(env, i, &nb_path_needed, tmp) == -1)
					return (-1);
			}
			i++;
		}
	}
	return (0);
}
