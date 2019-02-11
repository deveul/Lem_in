/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:46:39 by smakni            #+#    #+#             */
/*   Updated: 2019/02/11 20:26:03 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>
/*
static void	aff_data(int *pred, int *distance, int i)
{
	ft_printf("distance[%d] = %4d | ", i, distance[i]);
	ft_printf("pred[%d] = %d\n", i, pred[i]);
}
*/
void     dijkstra(int **matrice,int n, int startnode, int endnode)
{
	int distance[n];
	int pred[n];
	int visited[n];
	int count;
	int	mindistance;
	int nextnode;
	int i;
	int j;
	int *path;
	
	//endnode = 0;
	i = 0;
	while (i < n)
	{	
		distance[i] = matrice[startnode][i];
		pred[i] = startnode;
		visited[i] = 0;
//		aff_data(pred, distance, i);
		i++;
	}
	distance[startnode] = 0;
	visited[startnode] = 1;
	count = 1;
	while(count < n - 1)
	{
//		ft_printf("\n----------------[%d]--------------------\n", count);
//		ft_printf("-------------------------------------\n");
		i = 0;
//		while (i < n)
//			aff_data(pred, distance, i++);
//		ft_printf("-------------------------------------\n");
//		ft_printf(">>>>>>>>>>>>>>>CHECK_1<<<<<<<<<<<<<<<<<<\n");
		//nextnode gives the node at minimum distance
		mindistance = 9999;
		i = 0;
		while (i < n)
		{
//			ft_printf("visited[%d] = %d | ", i ,visited[i]);
//			ft_printf("distance[%d] = %d < mindistance = %d\n", i, distance[i], mindistance);
			if (distance[i] < mindistance && !visited[i])
			{
//				ft_printf("MIN\n");
				//ft_printf("nextnode = %d\n", i);
				//aff_data(pred, distance, i);
				mindistance=distance[i];
				nextnode=i;
			}
			i++;
		}
		visited[nextnode] = 1;
//		ft_printf(">>>>>>>>>>>>>>>CHECK_2<<<<<<<<<<<<<<<<<<\n");
		//check if a better path exists through nextnode			
		i = 0;
		while (i < n)
		{
			if (!visited[i])
			{
//				ft_printf("visited[%d] = %d | ", i, visited[i]);
//				ft_printf("mindistance = %d + matrice[%d][%d] = %d < distance[%d] = %d\n", 
//							mindistance, nextnode, i, matrice[nextnode][i], i, distance[i]);
				if (mindistance + matrice[nextnode][i] < distance[i])
				{
//					ft_printf("YES\n");
					distance[i] = mindistance + matrice[nextnode][i];
					pred[i] = nextnode;
				}
			}
			i++;
		}
		count++;
	}
 
	//print the path and distance of each node
	i = 0;
	int len = 0;
	while (i < n)
	{
		if (i == endnode)
		{
			printf("\nDistance of node %d = %d", i ,distance[i]);
			len = distance[i];
			if (!(path = ft_memalloc(sizeof(int) * len)))
				return ;
			printf("\nPath_Dijkstra : ");
			path[len] = i;
			j=i;
			i = len;
			while ( j != startnode)
			{
				j = pred[j];
				path[--i] = j;
				//printf("\t%4d",j);
			}
			break ;
		}
		i++;
	}
	i = 0;
	while (i <= len)
		printf("%-7d",path[i++]);
}
