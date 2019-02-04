/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:33:26 by smakni            #+#    #+#             */
/*   Updated: 2019/02/04 14:16:13 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	fill_path(t_env *env, int index, int end)
{
	int i;
	int j;

	i = 0;
	j = 0;
	env->paths[index].connexions = ft_memalloc(100 * sizeof(char *))
	while (i < env->nb_nodes)
	{
		while (j < env->nodes[index].nb_edges)
		{
			
				
		}
}


void	algo(t_env *env)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	path = NULL;
	while (i < env->nb_nodes)
	{
		if (env->nodes[i]->start == 1)
		{
			env->path = ft_memalloc(sizeof(char *) * env->nodes[i]->nb_edges);
			break ;
		}
		i++;
	}

}	
