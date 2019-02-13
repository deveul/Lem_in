/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_data_dij.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:41:53 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/13 11:42:12 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	aff_data_1(int *dij.pred, int *dij.distance, int n, int count)
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
