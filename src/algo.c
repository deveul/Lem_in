/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 11:19:42 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/01 13:20:36 by smakni           ###   ########.fr       */
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
