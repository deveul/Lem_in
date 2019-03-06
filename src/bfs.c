/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:33:26 by smakni            #+#    #+#             */
/*   Updated: 2019/03/06 09:30:34 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static	void	check_nb_path(t_env *env)
{
	int i;

	i = 0;
	while (i < env->nb_nodes)
	{
		if (env->matrice[env->start_index][i] == 1
				&& env->flow[env->start_index][i] == 0)
			env->nb_path++;
		i++;
	}
}

static	int		check_path_end(t_env *env)
{
	int save;
	int i;

	i = 0;
	save = -1;
	while (i < env->nb_path)
	{
		if (env->paths[i].end_found == 1)
			save = i;
		env->paths[i].len--;
		i++;
	}
	return (save);
}

t_path			bfs(t_env *env)
{
	int		save;
	t_path	not_found;

	env->end_found = 0;
	check_nb_path(env);
	if (!(env->paths = ft_memalloc(sizeof(t_path) * env->nb_nodes)))
		exit(-1);
	env->nb_fifo = env->nb_path;
	if (init_paths(env) == -1)
		exit(-1);
	if (!(env->fifo = ft_memalloc(sizeof(t_fifo) * env->nb_nodes)))
		exit(-1);
	fill_initial_fifo(env);
	if (while_fifo(env) == -1)
		exit(-1);
	if ((save = check_path_end(env)) == -1)
	{
		not_found.len = -1;
		return (not_found);
	}
	return (env->paths[save]);
}
