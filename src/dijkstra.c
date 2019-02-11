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

void	aff_matrice(int len, int matrice[len][len])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			ft_printf("%4d|", matrice[i][j++]);
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

void	aff_data(int *pred, int *distance, int i)
{
	ft_printf("distance[%d] = %4d | ", i, distance[i]);
	ft_printf("pred[%d] = %4d\n", i, pred[i]);
}
void     dijkstra(int **matrice,int n,int startnode, int endnode)
{
	int cost[n][n],distance[n],pred[n];
	int visited[n],count,mindistance,nextnode,i,j;
	
	endnode= 0;
	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the cost matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(matrice[i][j]==0)
				cost[i][j]=9999;
			else
				cost[i][j]=matrice[i][j];	
	aff_matrice(n, cost);
	//initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{	
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
		aff_data(pred, distance, i);
	}
	distance[startnode] = 0;
	visited[startnode] = 1;
	count = 1;
	while(count < n - 1)
	{
		ft_printf("\n----------------[%d]--------------------\n", count);
		mindistance = 9999;
		//nextnode gives the node at minimum distance
		i = 0;
		while (i < n)
		{
			ft_printf("visited[%d] = %d\n", i ,visited[i]);
			ft_printf("%d < %d\n", distance[i], mindistance);
			if(distance[i] < mindistance && !visited[i])
			{
				//ft_printf("nextnode = %d\n", i);
				//aff_data(pred, distance, i);
				mindistance=distance[i];
				nextnode=i;
			}
			i++;
		}
		ft_printf("\n-------------------------------------\n");
		for(i=0;i<n;i++)
			aff_data(pred, distance, i);
		ft_printf("\n-------------------------------------\n");
		//check if a better path exists through nextnode			
		visited[nextnode]=1;
		i = 0;
		while (i < n)
		{
			if(!visited[i])
			{
				ft_printf(">>visited[%d] = %d\n", i, visited[i]);
				ft_printf("%d + %d < %d\n", mindistance, cost[nextnode][i], distance[i]);
				if(mindistance+cost[nextnode][i]<distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
			}
			i++;
		}
		distance[i]=mindistance+cost[nextnode][i];
		pred[i]=nextnode;
		count++;
	}
 
	//print the path and distance of each node
	for(i=0;i<n;i++)
		if(i!=startnode)
		{
			printf("\nDistance of node%d=%d",i,distance[i]);
			printf("\nPath=%d",i);
			
			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=startnode);
	}
}