/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_data_dij.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:41:53 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/13 18:30:33 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	aff_data_1(t_dij *dij, int n, int count)
{
   int i;

   i = 0;
   ft_printf("\n----------------[%d]--------------------\n", count);
   ft_printf("-------------------------------------\n");
   while (i < n)
   {
 	  	ft_printf("dij->distance[%d] = %4d | ", i, dij->distance[i]);
   		ft_printf("dij->pred[%d] = %d\n", i, dij->pred[i]);
		i++;
   }
   ft_printf("-------------------------------------\n");
}

void 	aff_data_2(t_dij *dij, int i)
{
	ft_printf("dij->visited[%d] = %d | ", i ,dij->visited[i]);
	ft_printf("dij->distance[%d] = %d < dij->min = %d\n",
		   	i, dij->distance[i], dij->min);
}

void 	aff_data_3(t_dij *dij, int i, t_env *env)
{
	ft_printf("dij->visited[%d] = %d | ", i, dij->visited[i]);
	ft_printf("dij->min = %d + matrice[%d][%d] = %d < dij->distance[%d] = %d\n",
					dij->min, dij->nextnode, i, env->matrice[dij->nextnode][i], i, dij->distance[i]);
}
