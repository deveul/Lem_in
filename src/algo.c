/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 11:19:42 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/06 16:23:30 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void			reset_paths(t_env *env)
{
	int		i;

	if (!env->nb_path)
		return ;
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
}

int				analyze_graph(t_env *env)
{
	int		i;

	init_flow(env);
	if (env->start >= 1 && env->end >= 1)
		edmonds_karp(env);
	i = 0;
	reset_paths(env);
	bfs_second(env, env->best_flow);
	print_path(env);
	free(env->fifo);
	if (env->nb_path == 0)
	{
		ft_putendl("No passaran");
		ft_putendl("ERROR");
		exit(-1);
	}
	return (0);
}
