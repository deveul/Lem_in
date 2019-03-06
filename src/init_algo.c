/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:08:47 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/03/06 16:27:51 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		init_paths(t_env *env)
{
	int		i;

	i = 0;
	env->rooms[env->start_index].check = 1;
	while (i < env->nb_path)
	{
		if (!(env->paths[i].path = ft_memalloc(sizeof(int) * env->nb_nodes)))
			return (-1);
		env->paths[i].path[0] = env->start_index;
		env->paths[i].len = 1;
		env->paths[i].end_found = 0;
		i++;
	}
	return (0);
}

int		init_paths_second(t_env *env)
{
	int		i;

	i = 0;
	env->rooms[env->start_index].check = 1;
	while (i < env->nb_path)
	{
		if (!(env->paths[i].path = ft_memalloc(sizeof(int) * env->nb_nodes)))
			return (-1);
		env->paths[i].path[0] = env->start_index;
		env->paths[i].len = 1;
		env->paths[i].end_found = 0;
		i++;
	}
	return (0);
}

void	fill_initial_fifo(t_env *env)
{
	int		i;
	int		path_index;

	i = 0;
	path_index = 0;
	while (i < env->nb_nodes)
	{
		if (env->matrice[env->start_index][i] == 1
				&& env->flow[env->start_index][i] == 0)
		{
			env->fifo[path_index].index = i;
			env->fifo[path_index].from = 0;
			env->fifo[path_index].path_index = path_index;
			env->rooms[i].check = 1;
			path_index++;
		}
		i++;
	}
}

void	fill_initial_fifo_second(t_env *env, char **flow)
{
	int		i;
	int		path_index;

	i = 0;
	path_index = 0;
	while (i < env->nb_nodes)
	{
		if (flow[env->start_index][i] == 1)
		{
			env->fifo[path_index].index = i;
			env->fifo[path_index].path_index = path_index;
			env->rooms[i].check = 1;
			path_index++;
		}
		i++;
	}
}

void	init_flow(t_env *env)
{
	int i;

	i = 0;
	ft_printf("ici env->nb_nodes:%d\n", env->nb_nodes);
	if (!(env->flow = ft_memalloc(sizeof(char *) * env->nb_nodes)))
		exit(-1);
	while (i < env->nb_nodes)
	{
		if (!(env->flow[i] = ft_memalloc(sizeof(char) * env->nb_nodes)))
			exit(-1);
		i++;
	}
}
