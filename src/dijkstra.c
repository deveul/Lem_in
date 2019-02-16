/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:46:39 by smakni            #+#    #+#             */
/*   Updated: 2019/02/16 03:42:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>
	
static int	save_path(t_env *env, int index, t_dij *dij)
{
	t_path 	tmp;
	t_res	*tmp_res;
	int 	j;
	int 	i;
	int 	x;

	i = 0;
	x = 0;
	j = 0;
	while (i < env->nb_nodes)
	{
		if (i == env->end_index)
		{
			if (dij->distance[i] == INFINITE || dij->distance[i] == 0)
				return (-1);
			tmp.path = ft_memalloc(sizeof(int) * (dij->distance[i] + 1));
			tmp.len = dij->distance[i];
			x = tmp.len;
			tmp.path[x] = i;
			x--;
			j = i;
			while (j != env->start_index)
			{
				j = dij->pred[j];
				tmp.path[x] = j;
				x--;
			}
			if (env->nb_path_ok > 0)
			{
				tmp_res = env->results;
				while (tmp_res != NULL)
				{
					if (tmp.len == tmp_res->path.len 
						&& compare_paths(tmp, tmp_res->path) == 1)
						return (-1);	
					tmp_res = tmp_res->next;
				}
			}
			add_result(&env->results, tmp);
			if (index == 0)
				env->first_path = tmp;
			return (0);
		}
		i++;
	}
	return (-1);
}

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
	if (save_path(env, index, &dij) != -1)
		env->nb_path_ok++;
	update_matrice(env, index);
	free_dij(&dij);
	if (index == env->first_path.len)
		return (-1);
	return (0);
}

