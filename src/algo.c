/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 11:19:42 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/06 10:23:57 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int				analyze_graph(t_env *env)
{
	int		i;

	init_flow(env);
	if (env->start_nb >= 1 && env->end_nb >= 1)
		edmonds_karp(env);
	i = 0;
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
