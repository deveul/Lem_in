/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:46:39 by smakni            #+#    #+#             */
/*   Updated: 2019/02/13 19:15:11 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	save_path(t_env *env, int index, t_dij *dij)
{
	t_path tmp;
	int j;
	int i;
	int x;

	i = 0;
	x = 0;
	j = 0;
	while (i < env->nb_nodes)
	{
		if (i == env->end_index)
		{
			if (dij->distance[i] == 9999)
				break ;
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
			add_result(&env->results, tmp);
			if (index == 0)
				env->first_path = tmp;
			return (i);
		}
		i++;
	}
	return (-1);
}

static void	update_matrice(t_env *env, int index)
{
	if (index < env->first_path.len)
		env->matrice[env->first_path.path[index]][env->first_path.path[index + 1]] = 9999;
}

static void	init_dijkstra(t_dij *dij, t_env *env)
{
	int i;

	if (!(dij->distance = ft_memalloc(sizeof(int) * env->nb_nodes)))
		return ;
	if (!(dij->visited = ft_memalloc(sizeof(int) * env->nb_nodes)))
		return ;
	if (!(dij->pred = ft_memalloc(sizeof(int) * env->nb_nodes)))
		return ;
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

	ft_printf("\n>>>>>>>>>>>>>>>CHECK_1<<<<<<<<<<<<<<<<<<\n");
	//dij.nextnode gives the node at minimum dij.distance
	dij->min = 9999;
	i = 0;
	while (i < n)
	{
		aff_data_2(dij, i);
		if (dij->distance[i] < dij->min && !dij->visited[i])
		{
			dij->min = dij->distance[i];
			dij->nextnode = i;
		}
		i++;
	}
	dij->visited[dij->nextnode] = 1;
}

void	check_path_nextnode(t_env *env, t_dij *dij, int n)
{
	int i;

	ft_printf("\n>>>>>>>>>>>>>>>CHECK_2<<<<<<<<<<<<<<<<<<\n");
	/*check if a better path exists through dij.nextnode*/
	i = 0;
	while (i < n)
	{
		if (!dij->visited[i])
		{
			aff_data_3(dij, i, env);
			if (dij->min + env->matrice[dij->nextnode][i] < dij->distance[i])
			{
				ft_printf("YES\n");
				dij->distance[i] = dij->min + env->matrice[dij->nextnode][i];
				dij->pred[i] = dij->nextnode;
			}
		}
		i++;
	}
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
	int		i;

	i = 0;
	init_dijkstra(&dij, env);
	count = 1;
	while (count < n - 1)
	{
		aff_data_1(&dij, n, count);
		search_nextnode(&dij, n);
		check_path_nextnode(env, &dij, n);
		count++;
	}
	ft_printf("\n>>>>>>>>>>>>>>>>>END<<<<<<<<<<<<<<<<<<<\n");
	aff_data_1(&dij, n, count);
	if ((i = save_path(env, index, &dij)) != -1)
	{
		update_matrice(env, index);
		env->nb_path_ok++;
		free_dij(&dij);
	}
	else
	{
		free_dij(&dij);
		return (-1);
	}
	if (index == env->first_path.len)
		return (-1);
	return (0);
}

