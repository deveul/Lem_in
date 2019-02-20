/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:46:39 by smakni            #+#    #+#             */
/*   Updated: 2019/02/20 19:23:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void	init_dijkstra(t_dij *dij, t_env *env)
{
	int i;

	if (!(dij->distance = ft_memalloc(sizeof(int) * env->nb_nodes)))
		exit (-1);
	if (!(dij->visited = ft_memalloc(sizeof(int) * env->nb_nodes)))
		exit (-1);
	if (!(dij->pred = ft_memalloc(sizeof(int) * env->nb_nodes)))
		exit (-1);
	i = 0;
	while (i < env->nb_nodes)
	{
		dij->distance[i] = env->matrice[env->start_index][i];
		dij->pred[i] = env->start_index;
		dij->visited[i] = 0;
		i++;
	}
	dij->distance[env->start_index] = 0;
	dij->visited[env->start_index] = 1;
}

static void	search_nextnode(t_dij *dij, int n)
{
	int i;

	//ft_printf("\n>>>>>>>>>>>>>>>CHECK_1<<<<<<<<<<<<<<<<<<\n");
	dij->min = INFINITE;
	i = 0;
	while (i < n)
	{
//		aff_data_2(dij, i);
		if (dij->distance[i] < dij->min && !dij->visited[i])
		{
			dij->min = dij->distance[i];
			dij->nextnode = i;
		}
		i++;
	}
	dij->visited[dij->nextnode] = 1;
}

static int	check_path_nextnode(t_env *env, t_dij *dij, int n)
{
	int i;

	//ft_printf("\n>>>>>>>>>>>>>>>CHECK_2<<<<<<<<<<<<<<<<<<\n");
	i = 0;
	while (i < n)
	{			
	//	aff_data_3(dij, i, env);
		if (!dij->visited[i])
		{
			if (dij->min + env->matrice[dij->nextnode][i] < dij->distance[i])
			{
	//			ft_printf("YES\n");
				dij->distance[i] = dij->min + env->matrice[dij->nextnode][i];
				dij->pred[i] = dij->nextnode;
				if (i == env->end_index)
				{
					//ft_printf("END_[%d] = %s\n", i, env->rooms[i].name);
					break ;
				}
			}
		}
		i++;
	}
	return (i);
}

static void free_dij(t_dij *dij)
{
	free(dij->visited);
	free(dij->distance);
	free(dij->pred);
	//free(dij);
}

int			dijkstra(t_env *env, int n, int index)
{
	t_dij	dij;
	int		count;

	init_dijkstra(&dij, env);
	count = 1;
	while (count < n - 1)
	{
//		aff_data_1(&dij, n, count);
		search_nextnode(&dij, n);
		if (check_path_nextnode(env, &dij, n) == env->end_index)
			break ;
		count++;
	}
//	ft_printf("\n>>>>>>>>>>>>>>>>>END<<<<<<<<<<<<<<<<<<<\n");
//	aff_data_1(&dij, n, count);
	if (save_path(env, &dij) != -1)
		env->nb_path++;
	update_matrice_2(env, index);
	free_dij(&dij);
	return (0);
}

