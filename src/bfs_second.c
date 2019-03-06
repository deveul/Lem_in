/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_second.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:33:26 by smakni            #+#    #+#             */
/*   Updated: 2019/03/06 10:07:06 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void	check_nb_path(t_env *env, int **flow)
{
	int i;

	i = 0;
	while (i < env->nb_nodes)
	{
		if (flow[env->start_index][i] == 1)
			env->nb_path++;
		i++;
	}
	ft_printf("at first nb_path:%d\n", env->nb_path);
}

static void	cpy_paths(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->nb_path)
	{
		env->prepaths[i].len--;
		i++;
	}
	//if (!(env->paths = ft_memalloc(sizeof(t_path) * env->end_found)))
	//	exit(-1);
	i = 0;
	j = 0;
	while (i < env->nb_path)
	{
		if (env->prepaths[i].end_found == 1)
		{
			add_result(&env->results, env->prepaths[i]);
	//		env->paths[j] = env->prepaths[i];
			j++;
		}
		i++;
	}
	free(env->prepaths);
//	free(env->fifo);
	env->nb_path = env->end_found;
	ft_printf("nb_end_found:%d\n", env->end_found);
}

void		bfs_second(t_env *env, int **flow)
{
	int		nb_path_needed;

	nb_path_needed = 0;
	env->end_found = 0;
	check_nb_path(env, flow);
	if (!(env->prepaths = ft_memalloc(sizeof(t_path) * env->nb_nodes)))
		exit(-1);
	env->nb_fifo = env->nb_path;
	if (init_paths_second(env) == -1)
		exit(-1);
	if (!(env->fifo = ft_memalloc(sizeof(t_fifo) * env->nb_nodes)))
		exit(-1);
	fill_initial_fifo_second(env, flow);
	if (while_fifo_second(env, nb_path_needed, flow) == -1)
		exit(-1);
	ft_printf("nb_path:%d\n", env->nb_path);
	cpy_paths(env);
}
