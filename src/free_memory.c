/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 11:07:08 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/02/23 13:41:34 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void		free_memory(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->nb_nodes)
	{
		free(env->rooms[i].name);
		i++;
	}
	free(env->rooms);
	i = 0;
	while (i < env->nb_nodes)
	{
		free(env->matrice[i]);
		free(env->flow[i]);
		i++;
	}
	free(env->matrice);
	free(env->flow);
	i = 0;
	while (i < env->nb_f_c)
		free(env->combi[i++].index_array);
	free(env->final_combi[env->c_c].ants_by_index);
	free(env->combi);
	free(env->final_combi);
	free(env->start_links);
	free(env->end_links);
	free(env->paths);
}
