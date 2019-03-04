/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:46:39 by smakni            #+#    #+#             */
/*   Updated: 2019/03/04 12:48:01 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static	void	init_dijkstra(t_dij *dij, t_env *env)
{
	int i;

	if (!(dij->distance = ft_memalloc(sizeof(int) * env->nb_nodes)))
		exit(-1);
	if (!(dij->visited = ft_memalloc(sizeof(int) * env->nb_nodes)))
		exit(-1);
	if (!(dij->pred = ft_memalloc(sizeof(int) * env->nb_nodes)))
		exit(-1);
	i = 0;
	while (i < env->nb_nodes)
	{
		dij->distance[i] = env->flow[env->start_index][i];
		dij->pred[i] = env->start_index;
		dij->visited[i] = 0;
		i++;
	}
	dij->distance[env->start_index] = 0;
	dij->visited[env->start_index] = 1;
}

static	void	search_nextnode(t_dij *dij, t_env *env, int n)
{
	int i;

	dij->nextnode = 0;
	dij->min = INFINITE;
	i = 0;
	while (i < n)
	{
		if (env->rooms[i].check == 0 
			 && !dij->visited[i] && dij->distance[i] < dij->min)
		{
			dij->min = dij->distance[i];
			dij->nextnode = i;
		}
		i++;
	}
	dij->visited[dij->nextnode] = 1;
}

static	int		check_path_nextnode(t_env *env, t_dij *dij, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (env->rooms[i].check == 0 && !dij->visited[i])
		{
			if (dij->min + env->flow[dij->nextnode][i] < dij->distance[i])
			{
				dij->distance[i] = dij->min + env->flow[dij->nextnode][i];
				dij->pred[i] = dij->nextnode;
				if (i == env->end_index)
					break ;
			}
		}
		i++;
	}
	return (i);
}

static	void	free_dij(t_dij *dij)
{
	free(dij->visited);
	free(dij->distance);
	free(dij->pred);
}

int				dijkstra(t_env *env, int n)
{
	t_dij	dij;
	int		count;

	init_dijkstra(&dij, env);
	count = 1;
	while (count < n - 1)
	{
		search_nextnode(&dij, env, n);
		if (check_path_nextnode(env, &dij, n) == env->end_index)
			break ;
		count++;
	}
	save_path(env, &dij);
	free_dij(&dij);
	return (0);
}
