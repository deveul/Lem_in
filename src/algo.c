/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 11:19:42 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/05 23:34:29 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int				analyze_graph(t_env *env)
{
	int		i;
	int		trigger;

	init_flow(env);
	if (env->start_nb >= 1 && env->end_nb >= 1)
		trigger = edmonds_karp(env);
	i = 0;
	bfs_second(env, env->best_flow);
	free(env->fifo);
/*	while (i < env->start_nb)
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
	}*/
	if (env->nb_path == 0)
	{
		ft_putendl("No passaran");
		ft_putendl("ERROR");
		exit(-1);
	}
	return (0);
}
