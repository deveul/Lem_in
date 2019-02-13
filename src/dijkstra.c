/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:46:39 by smakni            #+#    #+#             */
/*   Updated: 2019/02/13 09:57:13 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>
/*
static void	aff_data_1(int *dij.pred, int *dij.distance, int n, int count)
{
   int i;

   i = 0;
   ft_printf("\n----------------[%d]--------------------\n", count);
   ft_printf("-------------------------------------\n");
   while (i < n)
   {	   
 	  	ft_printf("dij.distance[%d] = %4d | ", i, dij.distance[i]);
   		ft_printf("dij.pred[%d] = %d\n", i, dij.pred[i]);
		i++;
   }
   ft_printf("-------------------------------------\n");
   ft_printf(">>>>>>>>>>>>>>>CHECK_1<<<<<<<<<<<<<<<<<<\n");

}

static void aff_data_2(int *dij.distance, int *dij.visited, int i, int mindij.distance)
{
	ft_printf("dij.visited[%d] = %d | ", i ,dij.visited[i]);
	ft_printf("dij.distance[%d] = %d < mindij.distance = %d\n", i, dij.distance[i], mindij.distance);
}

static void aff_data_3(int *dij.distance, int *dij.visited, int i, int mindij.distance, t_env *env, int dij.nextnode)
{
	ft_printf("dij.visited[%d] = %d | ", i, dij.visited[i]);
				ft_printf("mindij.distance = %d + matrice[%d][%d] = %d < dij.distance[%d] = %d\n", 
							mindij.distance, dij.nextnode, i, env->matrice[dij.nextnode][i], i, dij.distance[i]);
}
*/
static int save_path(t_env *env, int index, t_dij *dij)
{
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
			env->paths[index].path = ft_memalloc(sizeof(int) * (dij->distance[i] + 1));
			env->paths[index].len = dij->distance[i];
			x = env->paths[index].len;
			ft_printf("\ndij.distance of node %d = %d", i ,dij->distance[i]);
			ft_printf("\nPath_Dijkstra : ");
			ft_printf("%4d", i);
			env->paths[index].path[x] = i;
			x--;
			j=i;
			while ( j != env->start_index)
			{
				j = dij->pred[j];
				env->paths[index].path[x] = j;
				x--;
				ft_printf("\t%4d",j);
			}
		}
		i++;
	}
	return (i);
}

static	void	update_matrice(t_dij *dij, t_env *env, int index, int i)
{
	if (dij->distance[i] != 9999)
	{
		i = 0;
		ft_putendl("");
		while (i <= env->paths[index].len)
		{
			ft_printf("%s-", env->rooms[env->paths[index].path[i]].name);
			i++;
		}
		ft_putendl("");
	}
	if (index < env->paths[0].len)
		env->matrice[env->paths[0].path[index]][env->paths[0].path[index + 1]] = 9999;
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

int     	dijkstra(t_env *env,int n, int index)
{
	t_dij	dij;
	int 	count;
	int 	i;

	i = 0;
	init_dijkstra(&dij, env);
	count = 1;
	while(count < n - 1)
	{
	//	aff_data_1(dij.pred, dij.distance, n, count);
		//dij.nextnode gives the node at minimum dij.distance
		dij.min = 9999;
		i = 0;
		while (i < n)
		{
	//		aff_data_2(dij, i, mindij.distance);
			if (dij.distance[i] < dij.min && !dij.visited[i])
			{
				dij.min = dij.distance[i];
				dij.nextnode=i;
			}
			i++;
		}
		dij.visited[dij.nextnode] = 1;
	//	ft_printf(">>>>>>>>>>>>>>>CHECK_2<<<<<<<<<<<<<<<<<<\n");
		//check if a better path exists through dij.nextnode			
		i = 0;
		while (i < n)
		{
			if (!dij.visited[i])
			{
	//			aff_data_3(dij, i, env);
				if (dij.min + env->matrice[dij.nextnode][i] < dij.distance[i])
				{
	//				ft_printf("YES\n");
					dij.distance[i] = dij.min + env->matrice[dij.nextnode][i];
					dij.pred[i] = dij.nextnode;
				}
			}
			i++;
		}
		count++;
	}
	i = save_path(env, index, &dij);
	update_matrice(&dij, env, index, i);
	if (index == env->paths[0].len)
		return (-1);
	return (0);
}
